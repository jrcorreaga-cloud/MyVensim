#include "funcional_tests.h"
#include "../../src/systemImpl.h"
#include "../../src/modelImpl.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;

// --- Equations ---

double ExponentialFlow::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}

double LogisticalFlow::execute() {
    if (getTarget() != nullptr) {
        return 0.01 * getTarget()->getValue() * (1.0 - (getTarget()->getValue() / 70.0));
    }
    return 0.0;
}

double ComplexFlow::execute() {
    if (getSource() != nullptr) {
        return 0.01 * getSource()->getValue();
    }
    return 0.0;
}

// --- Test Cases ---

void exponentialFuncionalTest() {
    Model* m = new ModelImpl("Simulacion Exponencial");
    System* pop1 = new SystemImpl("pop1", 100.0);
    System* pop2 = new SystemImpl("pop2", 0.0);
    Flow* expFlow = new ExponentialFlow(pop1, pop2);

    m->add(pop1);
    m->add(pop2);
    m->add(expFlow);

    m->run(0, 100, 1);

    // Precise validation using original logic
    assert(round(pop1->getValue() * 10000) / 10000 == 36.6032);
    assert(round(pop2->getValue() * 10000) / 10000 == 63.3968);

    delete expFlow;
    delete pop2;
    delete pop1;
    delete m;
    
    cout << "Exponential Functional Test completed successfully." << endl;
}

void logisticalFuncionalTest() {
    Model* m = new ModelImpl("Simulacion Logistica");
    System* p1 = new SystemImpl("p1", 100.0);
    System* p2 = new SystemImpl("p2", 10.0);
    Flow* logFlow = new LogisticalFlow(p1, p2);

    m->add(p1);
    m->add(p2);
    m->add(logFlow);

    m->run(0, 100, 1);

    // Precise validation using original logic
    assert(round(p1->getValue() * 10000) / 10000 == 88.2167);
    assert(round(p2->getValue() * 10000) / 10000 == 21.7833);

    delete logFlow;
    delete p2;
    delete p1;
    delete m;
    
    cout << "Logistical Functional Test completed successfully." << endl;
}

void complexFuncionalTest() {
    Model* m = new ModelImpl("Simulacion Compleja");
    System* q1 = new SystemImpl("q1", 100.0);
    System* q2 = new SystemImpl("q2", 0.0);
    System* q3 = new SystemImpl("q3", 100.0);
    System* q4 = new SystemImpl("q4", 0.0);
    System* q5 = new SystemImpl("q5", 0.0);

    Flow* f = new ComplexFlow(q1, q2);
    Flow* g = new ComplexFlow(q1, q3);
    Flow* r = new ComplexFlow(q2, q5);
    Flow* t = new ComplexFlow(q2, q3);
    Flow* u = new ComplexFlow(q3, q4);
    Flow* v = new ComplexFlow(q4, q1);

    m->add(q1); m->add(q2); m->add(q3); m->add(q4); m->add(q5);
    m->add(f); m->add(g); m->add(r); m->add(t); m->add(u); m->add(v);

    m->run(0, 100, 1);

    assert(round(q1->getValue() * 10000) / 10000 == 31.8513);
    assert(round(q2->getValue() * 10000) / 10000 == 18.4003);
    assert(round(q3->getValue() * 10000) / 10000 == 77.1143);
    assert(round(q4->getValue() * 10000) / 10000 == 56.1728);
    assert(round(q5->getValue() * 10000) / 10000 == 16.4612);

    delete v; delete u; delete t; delete r; delete g; delete f;
    delete q5; delete q4; delete q3; delete q2; delete q1;
    delete m;
    
    cout << "Complex Functional Test completed successfully." << endl;
}