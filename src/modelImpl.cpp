#include "modelImpl.h"
#include "systemImpl.h"

System* ModelImpl::createSystem(const std::string& name, double value) {
    System* s = new SystemImpl(name, value);
    add(s);
    return s;
}

// Constructor
ModelImpl::ModelImpl(const std::string& name, double time) : name(name), time(time) {}

// Destructor
ModelImpl::~ModelImpl() {
    // Clean up systems
    for (System* s : systems) {
        delete s;
    }
    systems.clear();

    // Clean up flows
    for (Flow* f : flows) {
        delete f;
    }
    flows.clear();
}

void ModelImpl::add(System* system) {
    systems.push_back(system);
}

Model::systemIterator ModelImpl::systemBegin() {
    return systems.begin();
}

Model::systemIterator ModelImpl::systemEnd() {
    return systems.end();
}

void ModelImpl::add(Flow* flow) {
    flows.push_back(flow);
}

Model::flowIterator ModelImpl::flowBegin() {
    return flows.begin();
}

Model::flowIterator ModelImpl::flowEnd() {
    return flows.end();
}

void ModelImpl::setName(const std::string& name) {
    this->name = name;
}

std::string ModelImpl::getName() const {
    return name;
}

void ModelImpl::setTime(double time) {
    this->time = time;
}

double ModelImpl::getTime() const {
    return time;
}

void ModelImpl::run(double startTime, double endTime, double step) {
    this->time = startTime;

    for (double t = startTime; t < endTime; t += step) {
        std::vector<double> flowResults;
        for (auto f : flows) {
            flowResults.push_back(f->execute());
        }

        auto itFlow = flows.begin();
        for (double result : flowResults) {
            Flow* f = *itFlow;
            System* source = f->getSource();
            System* target = f->getTarget();

            if (source) source->setValue(source->getValue() - result);
            if (target) target->setValue(target->getValue() + result);
            
            ++itFlow;
        }
        
        this->time += step;
    }
}