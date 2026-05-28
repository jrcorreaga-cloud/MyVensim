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

/**
 * @class Model
 * @brief Manages the execution of the simulation.
 * 
 * The Model class aggregates Systems and Flows, acting as a container 
 * for the simulation components and providing the means to execute the simulation 
 * over a given timeframe.
 */
class Model {
private:
    vector<System*> systems; /**< Collection of subsystems in the simulation */
    vector<Flow*> flows;     /**< Collection of flows connecting the systems */

public:
    /**
     * @brief Default constructor for Model.
     */
    Model();

    /**
     * @brief Copy constructor for Model.
     * @param obj The Model object to copy.
     */
    Model(const Model& obj);

    /**
     * @brief Virtual destructor for Model.
     */
    virtual ~Model();

    /**
     * @brief Copy assignment operator.
     * @param obj The Model reference to assign from.
     * @return Model& A reference to the assigned object.
     */
    Model& operator=(const Model& obj);

    /**
     * @brief Adds a System to the simulation.
     * @param system Pointer to the System to be added.
     */
    void add(System* system);

    /**
     * @brief Adds a Flow to the simulation.
     * @param flow Pointer to the Flow to be added.
     */
    void add(Flow* flow);

    /**
     * @brief Executes the simulation.
     * Over the given time period, it iterates on the simulation step by step,
     * recalculating and transferring flow values among the connected Systems.
     * @param initialTime The starting point of the simulation.
     * @param finalTime The endpoint of the simulation.
     */
    void execute(int initialTime, int finalTime);
};

#endif