#include "flow.h"

Flow::Flow() : name(""), source(nullptr), target(nullptr) {}

Flow::Flow(string n, System* s, System* t) : name(n), source(s), target(t) {}

Flow::Flow(const Flow& obj) : name(obj.name), source(obj.source), target(obj.target) {}

Flow::~Flow() {}

Flow& Flow::operator=(const Flow& obj) {
    if (this != &obj) {
        name = obj.name;
        source = obj.source;
        target = obj.target;
    }
    return *this;
}

void Flow::setName(string n) { name = n; }
string Flow::getName() const { return name; }

void Flow::setSource(System* s) { source = s; }
System* Flow::getSource() const { return source; }

void Flow::setTarget(System* t) { target = t; }
System* Flow::getTarget() const { return target; }

void Flow::connect(System* s, System* t) {
    source = s;
    target = t;
}