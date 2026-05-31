#ifndef SYSTEMIMPL_H
#define SYSTEMIMPL_H

#include "system.h"

class SystemImpl : public System {
protected:
    std::string name;
    double value;

public:
        SystemImpl();
    SystemImpl(const std::string& name, double value);
    
        virtual ~SystemImpl();

    /**
     * @brief Implements System abstraction interface.
     */
    void setName(const std::string& name) override;
    std::string getName() const override;
    
    void setValue(double value) override;
    double getValue() const override;
};

#endif // SYSTEMIMPL_H