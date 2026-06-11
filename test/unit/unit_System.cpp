#include "unit_System.h"
#include <cassert>
#include <cmath>
#include "../../src/model.h"

void unit_System_constructor() {
    Model* m = Model::createModel();
    // Default constructor test
    System* s1 = m->createSystem();
    assert(s1->getName() == "");
    assert(std::fabs(s1->getValue() - 0.0) < 0.0001);
    delete s1; // Free memory

    // Parameterized constructor test
    System* s2 = m->createSystem("Sist1", 10.5);
    assert(s2->getName() == "Sist1");
    assert(std::fabs(s2->getValue() - 10.5) < 0.0001);
    delete s2;
    delete m;
}

void unit_System_destructor() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("TestDestructor", 0.0);
    delete s1; 
    delete m;
}

void unit_System_getName() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("SistName", 5.0);
    assert(s1->getName() == "SistName");
    delete s1;
    delete m;
}

void unit_System_setName() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem();
    s1->setName("NewName");
    assert(s1->getName() == "NewName");
    delete s1;
    delete m;
}

void unit_System_getValue() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem("SistValue", 100.0);
    assert(std::fabs(s1->getValue() - 100.0) < 0.0001);
    delete s1;
    delete m;
}

void unit_System_setValue() {
    Model* m = Model::createModel();
    System* s1 = m->createSystem();
    s1->setValue(50.5);
    assert(std::fabs(s1->getValue() - 50.5) < 0.0001);
    delete s1;
    delete m;
}

// Grouping function
void run_unit_tests_System() {
    unit_System_constructor();
    unit_System_destructor();
    unit_System_getName();
    unit_System_setName();
    unit_System_getValue();
    unit_System_setValue();
}