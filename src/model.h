#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include <string>
#include <vector>

class Model {
public:
    static Model* createModel(const std::string& name = "", double time = 0.0);
    virtual System* createSystem(const std::string& name = "", double value = 0.0) = 0;

    template <typename T_FLOW>
    Flow* createFlow(System* source = nullptr, System* target = nullptr) {
        Flow* flow = new T_FLOW(source, target);
        add(flow);
        return flow;
    }

    /**
     * @brief Exposes iterators without revealing the underlying data structures,
     * ensuring encapsulation according to the Information Hiding principles.
     */
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    virtual ~Model() {}

    /**
     * @brief Contract for managing System entities inside the simulation model.
     */
    virtual void add(System* system) = 0;
    virtual systemIterator systemBegin() = 0;
    virtual systemIterator systemEnd() = 0;

    /**
     * @brief Contract for managing Flow entities inside the simulation model.
     */
    virtual void add(Flow* flow) = 0;
    virtual flowIterator flowBegin() = 0;
    virtual flowIterator flowEnd() = 0;

    /**
     * @brief Core simulation lifecycle manager. Executes the operational loop.
     */
    virtual void run(double startTime, double endTime, double step) = 0;

    /**
     * @brief Metadata tracking methods.
     */
    virtual void setName(const std::string& name) = 0;
    virtual std::string getName() const = 0;
    
    virtual void setTime(double time) = 0;
    virtual double getTime() const = 0;
    virtual void incrementTime(double step) = 0;
};

#endif // MODEL_H