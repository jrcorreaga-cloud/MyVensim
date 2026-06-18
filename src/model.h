#ifndef MODEL_H
#define MODEL_H

#include "system.h"
#include "flow.h"
#include <string>
#include <vector>

class Model {
public:
    /**
     * @brief Destructor virtual para la interfaz Model.
     */
    virtual ~Model() {}

    /**
     * @brief Factory method to create a new Model.
     */
    static Model* createModel(const std::string& name = "", double time = 0.0);

    /**
     * @brief Crea un nuevo sistema dentro del modelo.
     */
    virtual System* createSystem(const std::string& name = "", double value = 0.0) = 0;

    /**
     * @brief Iteradores para sistemas y flujos.
     */
    typedef std::vector<System*>::iterator systemIterator;
    typedef std::vector<Flow*>::iterator flowIterator;

    virtual systemIterator systemBegin() = 0;
    virtual systemIterator systemEnd() = 0;
    virtual flowIterator flowBegin() = 0;
    virtual flowIterator flowEnd() = 0;

    /**
     * @brief Ejecuta la simulación.
     */
    virtual void run(double startTime, double endTime, double step) = 0;

    /**
     * @brief Getters y Setters de metadatos.
     */
    virtual void setName(const std::string& name) = 0;
    virtual std::string getName() const = 0;
    
    virtual void setTime(double time) = 0;
    virtual double getTime() const = 0;
    virtual void incrementTime(double step) = 0;

    /**
     * @brief Template para la creación de flujos. Declarado en la interfaz pero implementado fuera.
     */
    template <typename T_FLOW>
    Flow* createFlow(System* source = nullptr, System* target = nullptr);

protected:
    /**
     * @brief Añade un sistema/flujo al modelo.
     */
    virtual void add(System* system) = 0;
    virtual void add(Flow* flow) = 0;
};

#include "flowImpl.h"

template <typename T_FLOW>
Flow* Model::createFlow(System* source, System* target) {
    Flow* flow = new FlowHandle(new T_FLOW(source, target));
    add(flow);
    return flow;
}

#endif // MODEL_H
