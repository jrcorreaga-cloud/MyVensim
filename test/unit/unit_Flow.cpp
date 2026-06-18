#include "unit_Flow.h"
#include <cassert>
#include <cmath>
#include "../../src/model.h"
#include "../../src/flowImpl.h"

// As FlowImpl is hidden, we create a concrete test flow body.
class DummyFlowBody : public FlowBody {
public:
    DummyFlowBody(System* source = nullptr, System* target = nullptr) : FlowBody(source, target) {}
    ~DummyFlowBody() {}
    
    // We implement the pure method returning a constant to isolate tests
    double execute() override {
        return 10.0;
    }
};

void unit_Flow_constructor() {
    // Default constructor
    Flow* f1 = new FlowHandle();
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);
    delete f1;

    // Parameterized constructor
    Model* m = Model::createModel();
    System* s1 = m->createSystem("S1", 10.0);
    System* s2 = m->createSystem("S2", 20.0);
    Flow* f2 = new FlowHandle(new DummyFlowBody(s1, s2));
    assert(f2->getSource() == s1);
    assert(f2->getTarget() == s2);
    
    delete f2;
    delete m;
}

void unit_Flow_destructor() {
    Flow* f1 = new FlowHandle();
    delete f1; 
}

void unit_Flow_setSource() {
    Flow* f1 = new FlowHandle();
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Src", 5.0);
    
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    
    delete f1;
    delete m;
}

void unit_Flow_getSource() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Src", 5.0);
    Flow* f1 = new FlowHandle(new DummyFlowBody(s1, nullptr));
    
    assert(f1->getSource() == s1);
    
    delete f1;
    delete m;
}

void unit_Flow_clearSource() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Src", 5.0);
    Flow* f1 = new FlowHandle(new DummyFlowBody(s1, nullptr));
    
    f1->clearSource();
    assert(f1->getSource() == nullptr);
    
    delete f1;
    delete m;
}

void unit_Flow_setTarget() {
    Flow* f1 = new FlowHandle();
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Tgt", 5.0);
    
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);
    
    delete f1;
    delete m;
}

void unit_Flow_getTarget() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Tgt", 5.0);
    Flow* f1 = new FlowHandle(new DummyFlowBody(nullptr, s1));
    
    assert(f1->getTarget() == s1);
    
    delete f1;
    delete m;
}

void unit_Flow_clearTarget() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Tgt", 5.0);
    Flow* f1 = new FlowHandle(new DummyFlowBody(nullptr, s1));
    
    f1->clearTarget();
    assert(f1->getTarget() == nullptr);
    
    delete f1;
    delete m;
}

void unit_Flow_execute() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("Src", 100.0);
    Flow* f1 = new FlowHandle(new DummyFlowBody(s1, nullptr));
    
    // Our DummyFlowBody returns a constant 10.0
    assert(std::fabs(f1->execute() - 10.0) < 0.0001); 
    
    delete f1;
    delete m;
}

// Grouping function
void run_unit_tests_Flow() {
    unit_Flow_constructor();
    unit_Flow_destructor();
    unit_Flow_setSource();
    unit_Flow_getSource();
    unit_Flow_clearSource();
    unit_Flow_setTarget();
    unit_Flow_getTarget();
    unit_Flow_clearTarget();
    unit_Flow_execute();
}
