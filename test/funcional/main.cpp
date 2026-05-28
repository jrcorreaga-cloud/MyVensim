/**
 * @file test/funcional/main.cpp
 * @brief Entry point for running functional tests.
 */

#ifndef MAIN_FUNCIONAL_TESTS
#define MAIN_FUNCIONAL_TESTS

#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"

int main() {
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();
    
    return 0; 
}

#endif