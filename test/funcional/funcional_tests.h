#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flowImpl.h"

class ExponentialFlow : public FlowImpl {
public:
    ExponentialFlow(System* source = nullptr, System* target = nullptr) : FlowImpl(source, target) {}
    double execute() override;
};

class LogisticalFlow : public FlowImpl {
public:
    LogisticalFlow(System* source = nullptr, System* target = nullptr) : FlowImpl(source, target) {}
    double execute() override;
};

class ComplexFlow : public FlowImpl {
public:
    ComplexFlow(System* source = nullptr, System* target = nullptr) : FlowImpl(source, target) {}
    double execute() override;
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_H