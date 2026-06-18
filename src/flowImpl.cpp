#include "flowImpl.h"

// FlowBody Implementation
FlowBody::FlowBody(System* source, System* target) : source(source), target(target) {}

FlowBody::~FlowBody() {}

void FlowBody::setSource(System* source) {
    this->source = source;
}

System* FlowBody::getSource() const {
    return source;
}

void FlowBody::clearSource() {
    source = nullptr;
}

void FlowBody::setTarget(System* target) {
    this->target = target;
}

System* FlowBody::getTarget() const {
    return target;
}

void FlowBody::clearTarget() {
    target = nullptr;
}

double FlowBody::execute() {
    return 0.0; // Default implementation
}

// FlowHandle Implementation
FlowHandle::FlowHandle(FlowBody* body) : Handle<FlowBody>(body) {}

FlowHandle::~FlowHandle() {}

void FlowHandle::setSource(System* source) {
    pImpl_->setSource(source);
}

System* FlowHandle::getSource() const {
    return pImpl_->getSource();
}

void FlowHandle::clearSource() {
    pImpl_->clearSource();
}

void FlowHandle::setTarget(System* target) {
    pImpl_->setTarget(target);
}

System* FlowHandle::getTarget() const {
    return pImpl_->getTarget();
}

void FlowHandle::clearTarget() {
    pImpl_->clearTarget();
}

double FlowHandle::execute() {
    return pImpl_->execute();
}
