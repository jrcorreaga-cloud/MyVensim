#include "systemImpl.h"

SystemImpl::SystemImpl() : name(""), value(0.0) {}

SystemImpl::SystemImpl(const std::string& name, double value) : name(name), value(value) {}

SystemImpl::~SystemImpl() {}

void SystemImpl::setName(const std::string& name) {
    this->name = name;
}

std::string SystemImpl::getName() const {
    return name;
}

void SystemImpl::setValue(double value) {
    this->value = value;
}

double SystemImpl::getValue() const {
    return value;
}