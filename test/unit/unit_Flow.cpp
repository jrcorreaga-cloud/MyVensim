#include "unit_Flow.h"
#include <cassert>
#include "../../src/flow.h"
#include "../../src/flowImpl.h"
#include "../../src/system.h"
#include "../../src/systemImpl.h"

// As FlowImpl is abstract (execute() is pure), we create a concrete test flow.
class TestFlow : public FlowImpl {
public:
    TestFlow(System* source = nullptr, System* target = nullptr) : FlowImpl(source, target) {}
    
    // We implement the pure method so the class can be instantiated
    double execute() override {
        if (getSource() != nullptr) {
            return getSource()->getValue() * 0.1; 
        }
        return 0.0;
    }
};

void unit_Flow_constructor() {
    // Default constructor
    Flow* f1 = new TestFlow();
    assert(f1->getSource() == nullptr);
    assert(f1->getTarget() == nullptr);
    delete f1;

    // Parameterized constructor
    System* s1 = new SystemImpl("S1", 10.0);
    System* s2 = new SystemImpl("S2", 20.0);
    Flow* f2 = new TestFlow(s1, s2);
    assert(f2->getSource() == s1);
    assert(f2->getTarget() == s2);
    
    delete f2;
    delete s1;
    delete s2;
}

void unit_Flow_destructor() {
    Flow* f1 = new TestFlow();
    delete f1; 
    // We verify that there are no leaks when destroying the polymorphic interface
}

void unit_Flow_setSource() {
    Flow* f1 = new TestFlow();
    System* s1 = new SystemImpl("Src", 5.0);
    
    f1->setSource(s1);
    assert(f1->getSource() == s1);
    
    delete f1;
    delete s1;
}

void unit_Flow_getSource() {
    System* s1 = new SystemImpl("Src", 5.0);
    Flow* f1 = new TestFlow(s1, nullptr);
    
    assert(f1->getSource() == s1);
    
    delete f1;
    delete s1;
}

void unit_Flow_clearSource() {
    System* s1 = new SystemImpl("Src", 5.0);
    Flow* f1 = new TestFlow(s1, nullptr);
    
    f1->clearSource();
    assert(f1->getSource() == nullptr);
    
    delete f1;
    delete s1;
}

void unit_Flow_setTarget() {
    Flow* f1 = new TestFlow();
    System* s1 = new SystemImpl("Tgt", 5.0);
    
    f1->setTarget(s1);
    assert(f1->getTarget() == s1);
    
    delete f1;
    delete s1;
}

void unit_Flow_getTarget() {
    System* s1 = new SystemImpl("Tgt", 5.0);
    Flow* f1 = new TestFlow(nullptr, s1);
    
    assert(f1->getTarget() == s1);
    
    delete f1;
    delete s1;
}

void unit_Flow_clearTarget() {
    System* s1 = new SystemImpl("Tgt", 5.0);
    Flow* f1 = new TestFlow(nullptr, s1);
    
    f1->clearTarget();
    assert(f1->getTarget() == nullptr);
    
    delete f1;
    delete s1;
}

void unit_Flow_execute() {
    System* s1 = new SystemImpl("Src", 100.0);
    Flow* f1 = new TestFlow(s1, nullptr);
    
    // Our TestFlow multiplies by 0.1
    assert(f1->execute() == 10.0); 
    
    delete f1;
    delete s1;
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