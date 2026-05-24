#include "system.h"

System::System() : name(""), value(0.0) {}

System::System(string n, double v) : name(n), value(v) {}

System::System(const System& obj) : name(obj.name), value(obj.value) {}

System::~System() {}

System& System::operator=(const System& obj) {
    if (this != &obj) {
        name = obj.name;
        value = obj.value;
    }
    return *this;
}

void System::setName(string n) { name = n; }
string System::getName() const { return name; }

void System::setValue(double v) { value = v; }
double System::getValue() const { return value; }