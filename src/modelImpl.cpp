#include "modelImpl.h"

// Constructor
ModelImpl::ModelImpl(const std::string& name, double time) : name(name), time(time) {}

// Destructor
ModelImpl::~ModelImpl() {
    /** 
     * Architectural Note: Following aggregation semantics, the Model refrains from
     * destroying System and Flow instances directly. Responsibility lies with the client.
     */
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

void ModelImpl::incrementTime(double step) {
    this->time += step;
}

void ModelImpl::run(double startTime, double endTime, double step) {
        this->time = startTime;

        for (double t = startTime; t < endTime; t += step) {
        
                std::vector<double> flowResults(flows.size());

                for (size_t i = 0; i < flows.size(); ++i) {
            flowResults[i] = flows[i]->execute();
        }

                for (size_t i = 0; i < flows.size(); ++i) {
            System* source = flows[i]->getSource();
            System* target = flows[i]->getTarget();

            if (source != nullptr) {
                source->setValue(source->getValue() - flowResults[i]);
            }
            if (target != nullptr) {
                target->setValue(target->getValue() + flowResults[i]);
            }
        }
        
                incrementTime(step);
    }
}