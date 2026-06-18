#include "systemImpl.h"

#ifdef DEBUGING
    int numHandleCreated = 0;
    int numHandleDeleted = 0;
    int numBodyCreated = 0;
    int numBodyDeleted = 0;
#endif

// SystemBody Implementation
SystemBody::SystemBody() : name(""), value(0.0) {
#ifdef DEBUGING
    numBodyCreated++;
#endif
}

SystemBody::SystemBody(const std::string& name, double value) : name(name), value(value) {
#ifdef DEBUGING
    numBodyCreated++;
#endif
}

SystemBody::~SystemBody() {
#ifdef DEBUGING
    numBodyDeleted++;
#endif
}

void SystemBody::setName(const std::string& name) {
    this->name = name;
}

std::string SystemBody::getName() const {
    return name;
}

void SystemBody::setValue(double value) {
    this->value = value;
}

double SystemBody::getValue() const {
    return value;
}

// SystemHandle Implementation
SystemHandle::SystemHandle() : Handle<SystemBody>() {
#ifdef DEBUGING
    numHandleCreated++;
#endif
}

SystemHandle::SystemHandle(const std::string& name, double value) : Handle<SystemBody>() {
    pImpl_->setName(name);
    pImpl_->setValue(value);
#ifdef DEBUGING
    numHandleCreated++;
#endif
}

SystemHandle::SystemHandle(const SystemHandle& other) : Handle<SystemBody>(other) {
#ifdef DEBUGING
    numHandleCreated++;
#endif
}

SystemHandle::~SystemHandle() {
#ifdef DEBUGING
    numHandleDeleted++;
#endif
}

void SystemHandle::setName(const std::string& name) {
    pImpl_->setName(name);
}

std::string SystemHandle::getName() const {
    return pImpl_->getName();
}

void SystemHandle::setValue(double value) {
    pImpl_->setValue(value);
}

double SystemHandle::getValue() const {
    return pImpl_->getValue();
}
