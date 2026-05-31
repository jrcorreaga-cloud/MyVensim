#ifndef FLOWIMPL_H
#define FLOWIMPL_H

#include "flow.h"

class FlowImpl : public Flow {
protected:
    System* source;
    System* target;

public:
        FlowImpl(System* source = nullptr, System* target = nullptr);
    
    // Destructor
    virtual ~FlowImpl();

        void setSource(System* source) override;
    System* getSource() const override;
    void clearSource() override;

    void setTarget(System* target) override;
    System* getTarget() const override;
    void clearTarget() override;

            virtual double execute() = 0; 
};

#endif // FLOWIMPL_H