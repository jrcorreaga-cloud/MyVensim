#ifndef FLOW_H
#define FLOW_H

#include <string>
#include "system.h"

using namespace std;

class Flow {
protected:
    string name;
    System* source;
    System* target;

public:
    Flow();
    Flow(string name, System* source = nullptr, System* target = nullptr);
    Flow(const Flow& obj);
    virtual ~Flow();
    Flow& operator=(const Flow& obj);

    void setName(string name);
    string getName() const;
    void setSource(System* source);
    System* getSource() const;
    void setTarget(System* target);
    System* getTarget() const;
    
    void connect(System* source, System* target);
    virtual double execute() = 0;
};

#endif