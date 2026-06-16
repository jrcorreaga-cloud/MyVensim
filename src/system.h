#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

class System {
public:
    /** 
     * @brief Virtual destructor.
     */
    virtual ~System() {}

    /*
     * Defines the standard contract for a System (Stock/Container),
     * adhering to the Dependency Inversion Principle.
     * Clients should rely on this abstraction rather than concrete implementations.
     */
    virtual void setName(const std::string& name) = 0;
    virtual std::string getName() const = 0;
    
    virtual void setValue(double value) = 0;
    virtual double getValue() const = 0;
};

#endif // SYSTEM_H