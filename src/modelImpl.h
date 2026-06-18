#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"
#include "handleBody.h"
#include <vector>

/**
 * @class ModelBody
 * @brief The Body class for Model, implementing the actual data and logic.
 */
class ModelBody : public Body {
protected:
    std::string name; /**< Name of the model. */
    double time;      /**< Current simulation time. */
    std::vector<System*> systems; /**< List of systems in the model. */
    std::vector<Flow*> flows;     /**< List of flows in the model. */

public:
    /**
     * @brief Default constructor.
     */
    ModelBody();

    /**
     * @brief Constructor with name.
     * @param name Name of the model.
     */
    ModelBody(const std::string& name);
    
    /**
     * @brief Destructor.
     */
    virtual ~ModelBody();

    /**
     * @brief Adds a system to the model.
     * @param system Pointer to the system.
     */
    void add(System* system);

    /**
     * @brief Adds a flow to the model.
     * @param flow Pointer to the flow.
     */
    void add(Flow* flow);

    /**
     * @brief Iterators for systems and flows.
     */
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    systemIterator systemBegin();
    systemIterator systemEnd();
    flowIterator flowBegin();
    flowIterator flowEnd();

    /**
     * @brief Runs the simulation.
     */
    void run(double startTime, double endTime, double step);

    /**
     * @brief Metadata accessors.
     */
    void setName(const std::string& name);
    std::string getName() const;
    void setTime(double time);
    double getTime() const;
    void incrementTime(double step);

private:
    /**
     * @brief Copy constructor (private).
     */
    ModelBody(const ModelBody& other);

    /**
     * @brief Assignment operator (private).
     */
    ModelBody& operator=(const ModelBody& other);
};

/**
 * @class ModelHandle
 * @brief The Handle class for Model, implementing the Model interface and managing a ModelBody.
 */
class ModelHandle : public Model, public Handle<ModelBody> {
public:
    /**
     * @brief Default constructor.
     */
    ModelHandle();

    /**
     * @brief Constructor with name.
     * @param name Name of the model.
     */
    ModelHandle(const std::string& name);

    /**
     * @brief Destructor.
     */
    virtual ~ModelHandle();

    /**
     * @brief Creates and adds a system (delegates to body).
     */
    System* createSystem(const std::string& name = "", double value = 0.0) override;

    /**
     * @brief Iterators (delegates to body).
     */
    systemIterator systemBegin() override;
    systemIterator systemEnd() override;
    flowIterator flowBegin() override;
    flowIterator flowEnd() override;

    /**
     * @brief Runs the simulation (delegates to body).
     */
    void run(double startTime, double endTime, double step) override;

    /**
     * @brief Metadata (delegates to body).
     */
    void setName(const std::string& name) override;
    std::string getName() const override;
    void setTime(double time) override;
    double getTime() const override;
    void incrementTime(double step) override;

protected:
    /**
     * @brief Adds a system (delegates to body).
     */
    void add(System* system) override;

    /**
     * @brief Adds a flow (delegates to body).
     */
    void add(Flow* flow) override;
};

#endif // MODELIMPL_H
