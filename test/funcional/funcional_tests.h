#ifndef FUNCIONAL_TESTS_H
#define FUNCIONAL_TESTS_H

#include "../../src/flow.h"

class ExponentialFlow : public Flow {
protected:
    System* source;
    System* target;
public:
    ExponentialFlow(System* source = nullptr, System* target = nullptr) : source(source), target(target) {}
    ~ExponentialFlow() {}
    void setSource(System* source) override { this->source = source; }
    System* getSource() const override { return source; }
    void clearSource() override { source = nullptr; }
    void setTarget(System* target) override { this->target = target; }
    System* getTarget() const override { return target; }
    void clearTarget() override { target = nullptr; }
    double execute() override;
};

class LogisticalFlow : public Flow {
protected:
    System* source;
    System* target;
public:
    LogisticalFlow(System* source = nullptr, System* target = nullptr) : source(source), target(target) {}
    ~LogisticalFlow() {}
    void setSource(System* source) override { this->source = source; }
    System* getSource() const override { return source; }
    void clearSource() override { source = nullptr; }
    void setTarget(System* target) override { this->target = target; }
    System* getTarget() const override { return target; }
    void clearTarget() override { target = nullptr; }
    double execute() override;
};

class ComplexFlow : public Flow {
protected:
    System* source;
    System* target;
public:
    ComplexFlow(System* source = nullptr, System* target = nullptr) : source(source), target(target) {}
    ~ComplexFlow() {}
    void setSource(System* source) override { this->source = source; }
    System* getSource() const override { return source; }
    void clearSource() override { source = nullptr; }
    void setTarget(System* target) override { this->target = target; }
    System* getTarget() const override { return target; }
    void clearTarget() override { target = nullptr; }
    double execute() override;
};

void exponentialFuncionalTest();
void logisticalFuncionalTest();
void complexFuncionalTest();

#endif // FUNCIONAL_TESTS_H