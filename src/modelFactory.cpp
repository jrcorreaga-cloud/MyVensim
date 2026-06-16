#include "modelFactory.h"
#include "modelImpl.h"

Model* ModelFactory::createModel(const std::string& name, double time) {
    return new ModelImpl(name, time);
}
