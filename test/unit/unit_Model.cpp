#include "unit_Model.h"
#include <cassert>
#include <cmath>
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/flowImpl.h"

class DummyFlow : public FlowBody {
public:
    DummyFlow(System* source = nullptr, System* target = nullptr) : FlowBody(source, target) {}
    ~DummyFlow() {}
    
    // Predictable equation: Always transfers a constant value of 10.0
    double execute() override {
        return 10.0;
    }
};

void unit_Model_constructor() {
    // Default constructor
    Model* m1 = Model::createModel();
    assert(m1->getName() == "");
    assert(std::fabs(m1->getTime() - 0.0) < 0.0001);
    // Verify that it starts empty
    assert(m1->systemBegin() == m1->systemEnd()); 
    assert(m1->flowBegin() == m1->flowEnd());
    delete m1;

    // Parameterized constructor
    Model* m2 = Model::createModel("Sim1", 10.0);
    assert(m2->getName() == "Sim1");
    assert(std::fabs(m2->getTime() - 10.0) < 0.0001);
    delete m2;
}

void unit_Model_destructor() {
    Model* m1 = Model::createModel();
    delete m1; // We validate there are no leaks on destruction
}

void unit_Model_addSystem() {
    Model* m1 = Model::createModel();
    System* s1 = m1->createSystem("S1", 10.0);
    
    assert(*(m1->systemBegin()) == s1); 
    
    // delete s1; // System is managed by Model in this version? 
    // Wait, ModelBody destructor deletes systems.
    delete m1;
}

void unit_Model_systemIterators() {
    Model* m1 = Model::createModel();
    System* s1 = m1->createSystem("S1", 10.0);
    System* s2 = m1->createSystem("S2", 20.0);
    
    int count = 0;
    for (auto it = m1->systemBegin(); it != m1->systemEnd(); ++it) {
        count++;
    }
    assert(count == 2);
    
    delete m1;
}

void unit_Model_addFlow() {
    Model* m1 = Model::createModel();
    Flow* f1 = m1->createFlow<DummyFlow>();
    
    assert(*(m1->flowBegin()) == f1);
    
    delete m1;
}

void unit_Model_flowIterators() {
    Model* m1 = Model::createModel();
    Flow* f1 = m1->createFlow<DummyFlow>();
    
    int count = 0;
    for (auto it = m1->flowBegin(); it != m1->flowEnd(); ++it) {
        count++;
    }
    assert(count == 1);
    
    delete m1;
}

void unit_Model_setName() {
    Model* m1 = Model::createModel();
    m1->setName("NuevoModelo");
    assert(m1->getName() == "NuevoModelo");
    delete m1;
}

void unit_Model_getName() {
    Model* m1 = Model::createModel("TestName", 0.0);
    assert(m1->getName() == "TestName");
    delete m1;
}

void unit_Model_setTime() {
    Model* m1 = Model::createModel();
    m1->setTime(5.5);
    assert(std::fabs(m1->getTime() - 5.5) < 0.0001);
    delete m1;
}

void unit_Model_getTime() {
    Model* m1 = Model::createModel("", 15.0);
    assert(std::fabs(m1->getTime() - 15.0) < 0.0001);
    delete m1;
}

void unit_Model_incrementTime() {
    Model* m1 = Model::createModel("", 0.0);
    m1->incrementTime(2.5);
    assert(std::fabs(m1->getTime() - 2.5) < 0.0001);
    delete m1;
}

void unit_Model_run() {
    Model* m1 = Model::createModel("SimRun", 0.0);
    System* s1 = m1->createSystem("Origen", 100.0); 
    System* s2 = m1->createSystem("Destino", 0.0); 
    Flow* f1 = m1->createFlow<DummyFlow>(s1, s2); // Transfers 10.0 at each step
    
    m1->run(0, 3, 1);
    
    assert(std::fabs(m1->getTime() - 3.0) < 0.0001);
    
    // 3 iterations * 10.0 transferred = 30.0 in total transferred
    assert(std::fabs(s1->getValue() - 70.0) < 0.0001); // 100.0 - 30.0 = 70.0
    assert(std::fabs(s2->getValue() - 30.0) < 0.0001); // 0.0 + 30.0 = 30.0
    
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
