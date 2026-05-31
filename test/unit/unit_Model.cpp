#include "unit_Model.h"
#include <cassert>
#include "../../src/model.h"
#include "../../src/modelImpl.h"
#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"

class TestFlowModel : public FlowImpl {
public:
    TestFlowModel(System* source = nullptr, System* target = nullptr) : FlowImpl(source, target) {}
    
    // Predictable equation: Always transfers a constant value of 1.5
    double execute() override {
        return 1.5;
    }
};

void unit_Model_constructor() {
    // Default constructor
    Model* m1 = new ModelImpl();
    assert(m1->getName() == "");
    assert(m1->getTime() == 0.0);
    // Verify that it starts empty
    assert(m1->systemBegin() == m1->systemEnd()); 
    assert(m1->flowBegin() == m1->flowEnd());
    delete m1;

    // Parameterized constructor
    Model* m2 = new ModelImpl("Sim1", 10.0);
    assert(m2->getName() == "Sim1");
    assert(m2->getTime() == 10.0);
    delete m2;
}

void unit_Model_destructor() {
    Model* m1 = new ModelImpl();
    delete m1; // We validate there are no leaks on destruction
}

void unit_Model_addSystem() {
    Model* m1 = new ModelImpl();
    System* s1 = new SystemImpl("S1", 10.0);
    
    m1->add(s1);
        assert(*(m1->systemBegin()) == s1); 
    
    delete s1;
    delete m1;
}

void unit_Model_systemIterators() {
    Model* m1 = new ModelImpl();
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 20.0);
    
    m1->add(s1);
    m1->add(s2);
    
    int count = 0;
    for (auto it = m1->systemBegin(); it != m1->systemEnd(); ++it) {
        count++;
    }
    assert(count == 2);
    
    delete s1;
    delete s2;
    delete m1;
}

void unit_Model_addFlow() {
    Model* m1 = new ModelImpl();
    Flow* f1 = new TestFlowModel();
    
    m1->add(f1);
    assert(*(m1->flowBegin()) == f1);
    
    delete f1;
    delete m1;
}

void unit_Model_flowIterators() {
    Model* m1 = new ModelImpl();
    Flow* f1 = new TestFlowModel();
    
    m1->add(f1);
    
    int count = 0;
    for (auto it = m1->flowBegin(); it != m1->flowEnd(); ++it) {
        count++;
    }
    assert(count == 1);
    
    delete f1;
    delete m1;
}

void unit_Model_setName() {
    Model* m1 = new ModelImpl();
    m1->setName("NuevoModelo");
    assert(m1->getName() == "NuevoModelo");
    delete m1;
}

void unit_Model_getName() {
    Model* m1 = new ModelImpl("TestName", 0.0);
    assert(m1->getName() == "TestName");
    delete m1;
}

void unit_Model_setTime() {
    Model* m1 = new ModelImpl();
    m1->setTime(5.5);
    assert(m1->getTime() == 5.5);
    delete m1;
}

void unit_Model_getTime() {
    Model* m1 = new ModelImpl("", 15.0);
    assert(m1->getTime() == 15.0);
    delete m1;
}

void unit_Model_incrementTime() {
    Model* m1 = new ModelImpl("", 0.0);
    m1->incrementTime(2.5);
    assert(m1->getTime() == 2.5);
    delete m1;
}

void unit_Model_run() {
    Model* m1 = new ModelImpl("SimRun", 0.0);
    System* s1 = new SystemImpl("Origen", 10.0); // Starts at 10
    System* s2 = new SystemImpl("Destino", 0.0); // Starts at 0
    Flow* f1 = new TestFlowModel(s1, s2); // Transfers 1.5 at each step
    
    m1->add(s1);
    m1->add(s2);
    m1->add(f1);
    
        m1->run(0, 3, 1);
    
        assert(m1->getTime() == 3.0);
    
    // 3 iterations * 1.5 transferred = 4.5 in total transferred
    assert(s1->getValue() == 5.5); // 10.0 - 4.5 = 5.5
    assert(s2->getValue() == 4.5); // 0.0 + 4.5 = 4.5
    
    delete f1;
    delete s2;
    delete s1;
    delete m1;
}

// Grouping function
void run_unit_tests_Model() {
    unit_Model_constructor();
    unit_Model_destructor();
    unit_Model_addSystem();
    unit_Model_systemIterators();
    unit_Model_addFlow();
    unit_Model_flowIterators();
    unit_Model_setName();
    unit_Model_getName();
    unit_Model_setTime();
    unit_Model_getTime();
    unit_Model_incrementTime();
    unit_Model_run();
}