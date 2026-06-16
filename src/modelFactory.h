#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include "model.h"
#include <string>

/**
 * @brief The ModelFactory class is responsible for creating instances of Model.
 * It follows the Factory Method pattern to decouple the client from concrete implementations.
 */
class ModelFactory {
public:
    /**
     * @brief Creates a new Model instance.
     * @param name Name of the model.
     * @param time Initial time of the model.
     * @return Pointer to the created Model.
     */
    static Model* createModel(const std::string& name = "", double time = 0.0);
};

#endif // MODELFACTORY_H
