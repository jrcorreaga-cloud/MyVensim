#include <iostream>
#include "modelFactory.h"
#include "system.h"
#include "model.h"

using namespace std;

int main() {
    // We now use the ModelFactory to decouple creation from the interface.
    Model* simulator = ModelFactory::createModel("Simulador Global", 0.0);
    
    // The model is now the factory and owner of its systems.
    simulator->createSystem("Poblacion", 100.0);
    simulator->createSystem("Recursos", 500.0);

    cout << "Model '" << simulator->getName() << "' loaded into memory." << endl;
    cout << "Registered systems: " << endl;
    
    // Collection traversal abstracts implementation details.
    for(auto it = simulator->systemBegin(); it != simulator->systemEnd(); ++it) {
        cout << "- " << (*it)->getName() << " : " << (*it)->getValue() << endl;
    }

    cout << "\nBase simulation ready to operate. (OK)" << endl;

    // Only delete the simulator; it will clean up its own systems and flows.
    delete simulator;

    return 0;
}