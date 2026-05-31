#ifndef UNIT_MODEL_H
#define UNIT_MODEL_H

// Declaration of unit test functions for Model
void unit_Model_constructor();
void unit_Model_destructor();
void unit_Model_addSystem();
void unit_Model_systemIterators();
void unit_Model_addFlow();
void unit_Model_flowIterators();
void unit_Model_setName();
void unit_Model_getName();
void unit_Model_setTime();
void unit_Model_getTime();
void unit_Model_incrementTime();
void unit_Model_run();

// Grouping function
void run_unit_tests_Model();

#endif // UNIT_MODEL_H