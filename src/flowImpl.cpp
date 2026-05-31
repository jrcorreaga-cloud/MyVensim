#include "flowImpl.h"

// Constructor
FlowImpl::FlowImpl(System* source, System* target) : source(source), target(target) {}

// Destructor
FlowImpl::~FlowImpl() {}

void FlowImpl::setSource(System* source) {
    this->source = source;
}

System* FlowImpl::getSource() const {
    return source;
}

void FlowImpl::clearSource() {
    this->source = nullptr;
}

void FlowImpl::setTarget(System* target) {
    this->target = target;
}

System* FlowImpl::getTarget() const {
    return target;
}

void FlowImpl::clearTarget() {
    this->target = nullptr;
}