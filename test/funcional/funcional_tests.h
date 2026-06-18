#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flowImpl.h"

class ExponentialFlow : public FlowBody {
public:
    ExponentialFlow(System* source = nullptr, System* target = nullptr) : FlowBody(source, target) {}
    ~ExponentialFlow() {}
    double execute() override;
};

class LogisticalFlow : public FlowBody {
public:
    LogisticalFlow(System* source = nullptr, System* target = nullptr) : FlowBody(source, target) {}
    ~LogisticalFlow() {}
    double execute() override;
};

class ComplexFlow : public FlowBody {
public:
    ComplexFlow(System* source = nullptr, System* target = nullptr) : FlowBody(source, target) {}
    ~ComplexFlow() {}
    double execute() override;
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_H
