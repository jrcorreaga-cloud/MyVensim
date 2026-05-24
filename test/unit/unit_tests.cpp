/**
 * @file test/unit/unit_tests.cpp
 * @brief Unit tests for basic classes: System, Flow, Model.
 */

#include "unit_tests.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include "../../src/model.h"
#include <iostream>
#include <cassert>

using namespace std;

// Concrete Dummy Flow just to test the base Flow methods
class DummyFlow : public Flow {
public:
    DummyFlow(string name = "") : Flow(name) {}
    double execute() override {
        return 0.0; 
    }
};

void system_unit_tests() {
    System s("TestSystem", 15.5);
    
    assert(s.getName() == "TestSystem");
    assert(s.getValue() == 15.5);
    
    s.setName("NewName");
    s.setValue(20.0);
    
    assert(s.getName() == "NewName");
    assert(s.getValue() == 20.0);
    
    cout << "System unit tests passed!" << endl;
}

void flow_unit_tests() {
    System src("Source", 10.0);
    System tgt("Target", 20.0);
    DummyFlow f("TestFlow");
    
    assert(f.getName() == "TestFlow");
    
    f.connect(&src, &tgt);
    
    assert(f.getSource() == &src);
    assert(f.getTarget() == &tgt);
    
    cout << "Flow unit tests passed!" << endl;
}

void model_unit_tests() {
    Model m;
    System s1("Sys1", 10.0);
    DummyFlow f1("Flow1");
    
    m.add(&s1);
    m.add(&f1);
    
    // Test that the model can run without crashing
    m.execute(0, 1);
    
    cout << "Model unit tests passed!" << endl;
}

void run_unit_tests_globals() {
    system_unit_tests();
    flow_unit_tests();
    model_unit_tests();
}