#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"
#include "handleBody.h"

/**
 * @class FlowBody
 * @brief The Body class for Flow, implementing the actual data and logic.
 */
class FlowBody : public Body {
protected:
    System* source; /**< Source system of the flow. */
    System* target; /**< Target system of the flow. */

public:
    /**
     * @brief Constructor with source and target.
     * @param source Pointer to the source system.
     * @param target Pointer to the target system.
     */
    FlowBody(System* source = nullptr, System* target = nullptr);
    
    /**
     * @brief Destructor.
     */
    virtual ~FlowBody();

    /**
     * @brief Sets the source system.
     * @param source Pointer to the source system.
     */
    void setSource(System* source);

    /**
     * @brief Gets the source system.
     * @return Pointer to the source system.
     */
    System* getSource() const;

    /**
     * @brief Clears the source system reference.
     */
    void clearSource();

    /**
     * @brief Sets the target system.
     * @param target Pointer to the target system.
     */
    void setTarget(System* target);

    /**
     * @brief Gets the target system.
     * @return Pointer to the target system.
     */
    System* getTarget() const;

    /**
     * @brief Clears the target system reference.
     */
    void clearTarget();

    /**
     * @brief Executes the flow equation. Must be implemented by subclasses.
     * @return The result of the flow calculation.
     */
    virtual double execute(); 

private:
    /**
     * @brief Copy constructor (private).
     */
    FlowBody(const FlowBody& other);

    /**
     * @brief Assignment operator (private).
     */
    FlowBody& operator=(const FlowBody& other);
};

/**
 * @class FlowHandle
 * @brief The Handle class for Flow, implementing the Flow interface and managing a FlowBody.
 */
class FlowHandle : public Flow, public Handle<FlowBody> {
public:
    /**
     * @brief Constructor with an existing FlowBody.
     * @param body Pointer to the FlowBody (takes ownership through ref counting).
     */
    FlowHandle(FlowBody* body = nullptr);

    /**
     * @brief Destructor.
     */
    virtual ~FlowHandle();

    /**
     * @brief Sets the source system (delegates to body).
     * @param source Pointer to the source system.
     */
    void setSource(System* source) override;

    /**
     * @brief Gets the source system (delegates to body).
     * @return Pointer to the source system.
     */
    System* getSource() const override;

    /**
     * @brief Clears the source system (delegates to body).
     */
    void clearSource() override;

    /**
     * @brief Sets the target system (delegates to body).
     * @param target Pointer to the target system.
     */
    void setTarget(System* target) override;

    /**
     * @brief Gets the target system (delegates to body).
     * @return Pointer to the target system.
     */
    System* getTarget() const override;

    /**
     * @brief Clears the target system (delegates to body).
     */
    void clearTarget() override;

    /**
     * @brief Executes the flow equation (delegates to body).
     * @return The result of the flow calculation.
     */
    double execute() override;
};

#endif // FLOWIMPL_H
