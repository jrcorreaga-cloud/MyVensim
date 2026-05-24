/**
 * @file src/model.h
 * @brief Model class that holds Systems and Flows and runs simulations.
 */

#ifndef MODEL_H
#define MODEL_H

#include <vector>
#include "system.h"
#include "flow.h"

using namespace std;

class Model {
private:
    vector<System*> systems;
    vector<Flow*> flows;

public:
    Model();
    Model(const Model& obj);
    virtual ~Model();
    Model& operator=(const Model& obj);

    void add(System* system);
    void add(Flow* flow);
    void execute(int initialTime, int finalTime);
};

#endif