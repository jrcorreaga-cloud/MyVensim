#include "unit_System.h"
#include <cassert>
#include <cmath>
#include "../../src/system.h"
#include "../../src/systemImpl.h"

void unit_System_constructor() {
    // Default constructor test
    System* s1 = new SystemImpl();
    assert(s1->getName() == "");
    assert(std::fabs(s1->getValue() - 0.0) < 0.0001);
    delete s1; // Free memory

    // Parameterized constructor test
    System* s2 = new SystemImpl("Sist1", 10.5);
    assert(s2->getName() == "Sist1");
    assert(std::fabs(s2->getValue() - 10.5) < 0.0001);
    delete s2;
}

void unit_System_destructor() {
        System* s1 = new SystemImpl("TestDestructor", 0.0);
    delete s1; 
    // If the architecture (virtual destructor) wasn't done well, 
    }

void unit_System_getName() {
    System* s1 = new SystemImpl("SistName", 5.0);
    assert(s1->getName() == "SistName");
    delete s1;
}

void unit_System_setName() {
    System* s1 = new SystemImpl();
    s1->setName("NewName");
    assert(s1->getName() == "NewName");
    delete s1;
}

void unit_System_getValue() {
    System* s1 = new SystemImpl("SistValue", 100.0);
    assert(std::fabs(s1->getValue() - 100.0) < 0.0001);
    delete s1;
}

void unit_System_setValue() {
    System* s1 = new SystemImpl();
    s1->setValue(50.5);
    assert(std::fabs(s1->getValue() - 50.5) < 0.0001);
    delete s1;
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