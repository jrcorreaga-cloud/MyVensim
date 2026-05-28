/**
 * @file test/funcional/funcional_tests.cpp
 * @brief Implementation of functional tests for the simulation model.
 * 
 * Includes tests for Exponential, Logistical, and Complex simulation behaviors
 * utilizing specific concrete Flow classes.
 */

#include "funcional_tests.h"
#include "../../src/model.h"
#include "../../src/system.h"
#include "../../src/flow.h"
#include <iostream>
#include <cassert>
#include <cmath>

using namespace std;

/**
 * @brief Utility function to check if a value is close enough to the expected result.
 * @param real The actual computed value.
 * @param awk The expected result.
 * @return true if they are deemed equal within a precision of 4 decimal places.
 */
inline bool rounded(double real, double awk) {
    double real_trunc = round(real * 10000.0) / 10000.0;
    return real_trunc == awk;
}

// Concrete Flows

/**
 * @class ExponentialFlow
 * @brief A flow that operates based on an exponential equation.
 */
class ExponentialFlow : public Flow {
public:
    ExponentialFlow(string name = "") : Flow(name) {}
    /**
     * @brief Computes the execution value for exponential behavior.
     * @return Transferred value corresponding to 1% of the source system's value.
     */
    double execute() override {
        return 0.01 * getSource()->getValue();
    }
};

/**
 * @class LogisticalFlow
 * @brief A flow that operates based on a logistical growth equation.
 */
class LogisticalFlow : public Flow {
public:
    LogisticalFlow(string name = "") : Flow(name) {}
    /**
     * @brief Computes the execution value for logistical behavior.
     * @return Transferred value considering maximum population capacity.
     */
    double execute() override {
        double pMax = 70.0;
        return 0.01 * getTarget()->getValue() * (1 - getTarget()->getValue() / pMax);
    }
};

/**
 * @class ComplexFlow
 * @brief A generic flow used in a multiple-system complex scenario.
 */
class ComplexFlow : public Flow {
public:
    ComplexFlow(string name = "") : Flow(name) {}
    /**
     * @brief Computes a standard transfer value.
     * @return Transferred value corresponding to 1% of the source system's value.
     */
    double execute() override {
        return 0.01 * getSource()->getValue();
    }
};

// Tests

/**
 * @brief Performs an exponential transfer test.
 * Expects the system to iteratively approach correct resulting population values.
 */
void exponentialFuncionalTest() {
    Model* model = new Model();
    System* pop1 = new System("pop1", 100.0);
    System* pop2 = new System("pop2", 0.0);
    Flow* expFlow = new ExponentialFlow("exponencia");
    
    expFlow->connect(pop1, pop2);
    model->add(pop1);
    model->add(pop2);
    model->add(expFlow);

    model->execute(0, 100);

    assert(rounded(pop1->getValue(), 36.6032));
    assert(rounded(pop2->getValue(), 63.3968));
    
    delete model; delete pop1; delete pop2; delete expFlow;
    cout << "Exponential functional test passed!" << endl;
}

/**
 * @brief Performs a logistical transfer test.
 * Evaluates the non-linear execution flow logic tied to a capacity ceiling.
 */
void logisticalFuncionalTest() {
    Model* model = new Model();
    System* p1 = new System("p1", 100.0);
    System* p2 = new System("p2", 10.0);
    Flow* logFlow = new LogisticalFlow("logistica");
    
    logFlow->connect(p1, p2);
    model->add(p1);
    model->add(p2);
    model->add(logFlow);

    model->execute(0, 100);

    assert(rounded(p1->getValue(), 88.2167));
    assert(rounded(p2->getValue(), 21.7833));

/**
 * @brief Performs a complex system interconnection test.
 * Simulates a large network of 5 systems and 6 flows. Asserts their final states
 * match expected calculated approximations after 100 time ticks.
 */
    delete model; delete p1; delete p2; delete logFlow;
    cout << "Logistical functional test passed!" << endl;
}

void complexFuncionalTest() {
    Model* model = new Model();
    System* q1 = new System("Q1", 100.0);
    System* q2 = new System("Q2", 0.0);
    System* q3 = new System("Q3", 100.0);
    System* q4 = new System("Q4", 0.0);
    System* q5 = new System("Q5", 0.0);

    Flow* f = new ComplexFlow("f"); f->connect(q1, q2);
    Flow* g = new ComplexFlow("g"); g->connect(q1, q3);
    Flow* u = new ComplexFlow("u"); u->connect(q3, q4);
    Flow* v = new ComplexFlow("v"); v->connect(q4, q1);
    Flow* t = new ComplexFlow("t"); t->connect(q2, q3);
    Flow* r = new ComplexFlow("r"); r->connect(q2, q5);

    model->add(q1); model->add(q2); model->add(q3); model->add(q4); model->add(q5);
    model->add(f); model->add(g); model->add(u); model->add(v); model->add(t); model->add(r);

    model->execute(0, 100);
    assert(rounded(q1->getValue(), 31.8513));
    assert(rounded(q2->getValue(), 18.4003));
    assert(rounded(q3->getValue(), 77.1143));
    assert(rounded(q4->getValue(), 56.1728));
    assert(rounded(q5->getValue(), 16.4612));

    delete model; delete q1; delete q2; delete q3; delete q4; delete q5;
    delete f; delete g; delete u; delete v; delete t; delete r;
    
    cout << "Complex functional test passed!" << endl;
}