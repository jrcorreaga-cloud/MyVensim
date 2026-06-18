#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H
#include "system.h"
#include "handleBody.h"

#define DEBUGING
#ifdef DEBUGING
    extern int numHandleCreated;
    extern int numHandleDeleted;
    extern int numBodyCreated;
    extern int numBodyDeleted;
#endif

/**
 * @class SystemBody
...
 * @brief The Body class for System, implementing the actual data and logic.
 */
class SystemBody : public Body {
protected:
    std::string name; /**< Name of the system. */
    double value;    /**< Current value of the system. */

public:
    /**
     * @brief Default constructor.
     */
    SystemBody();

    /**
     * @brief Constructor with name and value.
     * @param name Name of the system.
     * @param value Initial value of the system.
     */
    SystemBody(const std::string& name, double value);
    
    /**
     * @brief Destructor.
     */
    virtual ~SystemBody();

    /**
     * @brief Sets the name of the system.
     * @param name The new name.
     */
    void setName(const std::string& name);

    /**
     * @brief Gets the name of the system.
     * @return The name of the system.
     */
    std::string getName() const;
    
    /**
     * @brief Sets the value of the system.
     * @param value The new value.
     */
    void setValue(double value);

    /**
     * @brief Gets the value of the system.
     * @return The current value.
     */
    double getValue() const;

private:
    /**
     * @brief Copy constructor (private to prevent unauthorized copying).
     */
    SystemBody(const SystemBody& other);

    /**
     * @brief Assignment operator (private to prevent unauthorized copying).
     */
    SystemBody& operator=(const SystemBody& other);
};

/**
 * @class SystemHandle
 * @brief The Handle class for System, implementing the System interface and managing a SystemBody.
 */
class SystemHandle : public System, public Handle<SystemBody> {
public:
    /**
     * @brief Default constructor.
     */
    SystemHandle();

    /**
     * @brief Constructor with name and value.
     * @param name Name of the system.
     * @param value Initial value of the system.
     */
    SystemHandle(const std::string& name, double value);
    
    /**
     * @brief Copy constructor.
     */
    SystemHandle(const SystemHandle& other);

    /**
     * @brief Destructor.
     */
    virtual ~SystemHandle();

    /**
     * @brief Sets the name of the system (delegates to body).
     * @param name The new name.
     */
    void setName(const std::string& name) override;

    /**
     * @brief Gets the name of the system (delegates to body).
     * @return The name of the system.
     */
    std::string getName() const override;
    
    /**
     * @brief Sets the value of the system (delegates to body).
     * @param value The new value.
     */
    void setValue(double value) override;

    /**
     * @brief Gets the value of the system (delegates to body).
     * @return The current value.
     */
    double getValue() const override;
};

#endif // SYSTEMIMPL_H
