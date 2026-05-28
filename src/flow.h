/**
 * @file src/flow.h
 * @brief Abstract Flow class definition used to transfer values between Systems.
 */

#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

using namespace std;

/**
 * @class Flow
 * @brief Abstract base class representing a transfer of values between two Systems.
 * 
 * The Flow class connects a source System to a target System. Derived classes must 
 * implement the execute() method to define the specific behavior and transfer rate.
 */
class Flow {
protected:
    string name;     /**< The name of the flow */
    System* source;  /**< Pointer to the source System */
    System* target;  /**< Pointer to the target System */

public:
    /**
     * @brief Default constructor.
     * Initializes the flow with no name and null Systems.
     */
    Flow();

    /**
     * @brief Parameterized constructor.
     * @param name The name of the flow.
     * @param source Pointer to the source System (default is nullptr).
     * @param target Pointer to the target System (default is nullptr).
     */
    Flow(string name, System* source = nullptr, System* target = nullptr);

    /**
     * @brief Copy constructor for Flow.
     * @param obj The Flow object to copy.
     */
    Flow(const Flow& obj);

    /**
     * @brief Virtual destructor.
     */
    virtual ~Flow();

    /**
     * @brief Copy assignment operator.
     * @param obj The Flow reference to assign from.
     * @return Flow& A reference to the assigned object.
     */
    Flow& operator=(const Flow& obj);

    /**
     * @brief Sets the name of the flow.
     * @param name The new name of the flow.
     */
    void setName(string name);

    /**
     * @brief Gets the name of the flow.
     * @return string The name of the flow.
     */
    string getName() const;

    /**
     * @brief Sets the source System.
     * @param source Pointer to the new source System.
     */
    void setSource(System* source);

    /**
     * @brief Gets the source System.
     * @return System* Pointer to the current source System.
     */
    System* getSource() const;

    /**
     * @brief Sets the target System.
     * @param target Pointer to the new target System.
     */
    void setTarget(System* target);

    /**
     * @brief Gets the target System.
     * @return System* Pointer to the current target System.
     */
    System* getTarget() const;
    
    /**
     * @brief Helper method to set both source and target Systems.
     * @param source Pointer to the source System.
     * @param target Pointer to the target System.
     */
    void connect(System* source, System* target);

    /**
     * @brief Pure virtual method for flow execution.
     * Computes the amount of value transferred from source to target.
     * @return double The value to be transferred.
     */
    virtual double execute() = 0;
};

#endif