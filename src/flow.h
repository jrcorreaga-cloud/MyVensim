#ifndef FLOW_H
#define FLOW_H

#include "system.h"

class Flow {
public:
    /**
     * @brief Virtual destructor for polymorphic resolution.
     */
    virtual ~Flow() {}

    /**
     * @brief Defines the connection to the flow's origin system.
     * Follows the Single Responsibility Principle by confining source operations.
     */
    virtual void setSource(System* source) = 0;
    virtual System* getSource() const = 0;
    virtual void clearSource() = 0;

    /**
     * @brief Defines the connection to the flow's destination system.
     */
    virtual void setTarget(System* target) = 0;
    virtual System* getTarget() const = 0;
    virtual void clearTarget() = 0;

    /**
     * @brief Executes the numerical simulation operation for this specific flow.
     * Subclasses must implement their specific behavioral equations here.
     */
    virtual double execute() = 0;
};

#endif // FLOW_H