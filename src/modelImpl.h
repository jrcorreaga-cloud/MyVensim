#ifndef MODELIMPL_H
#define MODELIMPL_H

#include "model.h"
#include <vector>
#include <string>

class ModelImpl : public Model {
protected:
    std::string name;
    double time;
    std::vector<System*> systems;
    std::vector<Flow*> flows;

    /**
     * @brief Adds a System to the internal container.
     */
    void add(System* system) override;

    /**
     * @brief Adds a Flow to the internal container.
     */
    void add(Flow* flow) override;

public:
    ModelImpl(const std::string& name = "", double time = 0.0);
    virtual ~ModelImpl();

    System* createSystem(const std::string& name = "", double value = 0.0) override;

    systemIterator systemBegin() override;
    systemIterator systemEnd() override;
    flowIterator flowBegin() override;
    flowIterator flowEnd() override;

    void run(double startTime, double endTime, double step) override;

    void setName(const std::string& name) override;
    std::string getName() const override;
    
    void setTime(double time) override;
    double getTime() const override;

private:
    /**
     * @brief Copy constructor and assignment operator are private to prevent cloning,
     * maintaining the singleton/factory lifecycle control.
     */
    ModelImpl(const ModelImpl& other);
    ModelImpl& operator=(const ModelImpl& other);
};

#endif // MODELIMPL_H