#include "modelFactory.h"
#include "modelImpl.h"

Model* ModelFactory::createModel(const std::string& name, double time) {
    Model* m = new ModelHandle(name);
    m->setTime(time);
    return m;
}
