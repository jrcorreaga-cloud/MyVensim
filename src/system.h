/**
 * @file src/system.h
 * @brief Simple System class representing a stock with a name and numeric value.
 */

#ifndef SYSTEM_H
#define SYSTEM_H

#include <string>

using namespace std;

class System {
private:
    string name;
    double value;

public:
    System();
    System(string name, double value);
    System(const System& obj);
    virtual ~System();
    System& operator=(const System& obj);

    void setName(string name);
    string getName() const;
    void setValue(double value);
    double getValue() const;
};

#endif