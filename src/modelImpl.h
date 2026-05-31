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

public:
        ModelImpl(const std::string& name = "", double time = 0.0);
    virtual ~ModelImpl();

        void add(System* system) override;
    systemIterator systemBegin() override;
    systemIterator systemEnd() override;

        void add(Flow* flow) override;
    flowIterator flowBegin() override;
    flowIterator flowEnd() override;

        void run(double startTime, double endTime, double step) override;

        void setName(const std::string& name) override;
    std::string getName() const override;
    
    void setTime(double time) override;
    double getTime() const override;
    void incrementTime(double step) override;
};

#endif // MODELIMPL_H