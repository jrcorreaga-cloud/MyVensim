#include "modelImpl.h"
#include "systemImpl.h"
#include "flowImpl.h"
#include <algorithm>

// ModelBody Implementation
ModelBody::ModelBody() : name(""), time(0.0) {}

ModelBody::ModelBody(const std::string& name) : name(name), time(0.0) {}

ModelBody::~ModelBody() {
    systems.clear();
    flows.clear();
}

void ModelBody::add(System* system) {
    systems.push_back(system);
}

void ModelBody::add(Flow* flow) {
    flows.push_back(flow);
}

ModelBody::systemIterator ModelBody::systemBegin() { return systems.begin(); }
ModelBody::systemIterator ModelBody::systemEnd() { return systems.end(); }
ModelBody::flowIterator ModelBody::flowBegin() { return flows.begin(); }
ModelBody::flowIterator ModelBody::flowEnd() { return flows.end(); }

void ModelBody::run(double startTime, double endTime, double step) {
    for (double t = startTime; t < endTime; t += step) {
        std::vector<double> results;
        for (auto it = flowBegin(); it != flowEnd(); ++it) {
            results.push_back((*it)->execute());
        }

        int i = 0;
        for (auto it = flowBegin(); it != flowEnd(); ++it) {
            System* source = (*it)->getSource();
            System* target = (*it)->getTarget();
            if (source) source->setValue(source->getValue() - results[i]);
            if (target) target->setValue(target->getValue() + results[i]);
            i++;
        }
        time += step;
    }
}

void ModelBody::setName(const std::string& name) { this->name = name; }
std::string ModelBody::getName() const { return name; }
void ModelBody::setTime(double time) { this->time = time; }
double ModelBody::getTime() const { return time; }
void ModelBody::incrementTime(double step) { this->time += step; }

// ModelHandle Implementation
ModelHandle::ModelHandle() : Handle<ModelBody>() {}

Model* Model::createModel(const std::string& name, double time) {
    Model* m = new ModelHandle(name);
    m->setTime(time);
    return m;
}

ModelHandle::ModelHandle(const std::string& name) {
    pImpl_->setName(name);
}

ModelHandle::~ModelHandle() {}

System* ModelHandle::createSystem(const std::string& name, double value) {
    System* system = new SystemHandle(name, value);
    add(system);
    return system;
}

ModelHandle::systemIterator ModelHandle::systemBegin() { return pImpl_->systemBegin(); }
ModelHandle::systemIterator ModelHandle::systemEnd() { return pImpl_->systemEnd(); }
ModelHandle::flowIterator ModelHandle::flowBegin() { return pImpl_->flowBegin(); }
ModelHandle::flowIterator ModelHandle::flowEnd() { return pImpl_->flowEnd(); }

void ModelHandle::run(double startTime, double endTime, double step) {
    pImpl_->run(startTime, endTime, step);
}

void ModelHandle::setName(const std::string& name) { pImpl_->setName(name); }
std::string ModelHandle::getName() const { return pImpl_->getName(); }
void ModelHandle::setTime(double time) { pImpl_->setTime(time); }
double ModelHandle::getTime() const { return pImpl_->getTime(); }
void ModelHandle::incrementTime(double step) { pImpl_->incrementTime(step); }

void ModelHandle::add(System* system) { pImpl_->add(system); }
void ModelHandle::add(Flow* flow) { pImpl_->add(flow); }
