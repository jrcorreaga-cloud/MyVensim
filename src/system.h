/**
 * @file src/system.h
 * @brief Simple System class representing a stock with a name and numeric value.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

/**
 * @class System
 * @brief Represents a stock/system entity in the simulation.
 * 
 * The System class encapsulates a state variable with a given name and a double value.
 * It provides constructors, destructors, and accessors for managing this state.
 */
class System {
private:
    string name;  /**< The name of the system */
    double value; /**< The numeric value or state of the system */

public:
    /**
     * @brief Default constructor for System.
     * Initializes the system with an empty name and a value of 0.0.
     */
    System();

    /**
     * @brief Parameterized constructor for System.
     * @param name The name of the system.
     * @param value The initial value of the system.
     */
    System(string name, double value);

    /**
     * @brief Copy constructor for System.
     * @param obj The System object to copy.
     */
    System(const System& obj);

    /**
     * @brief Virtual destructor.
     */
    virtual ~System();

    /**
     * @brief Copy assignment operator.
     * @param obj The System reference to assign from.
     * @return System& A reference to the assigned object.
     */
    System& operator=(const System& obj);

    /**
     * @brief Sets the name of the system.
     * @param name The new name of the system.
     */
    void setName(string name);

    /**
     * @brief Gets the name of the system.
     * @return string The name of the system.
     */
    string getName() const;

    /**
     * @brief Sets the current value of the system.
     * @param value The new value.
     */
    void setValue(double value);

    /**
     * @brief Gets the current value of the system.
     * @return double The current value.
     */
    double getValue() const;
};

#endif