#include <iostream>
#include "system.h"
#include "model.h"
using namespace std;
int main() {
    // The client application targets abstraction boundaries instead of concrete structures,
// preserving the Dependency Inversion Principle.
    Model* simulator = Model::createModel("Simulador Global", 0.0);
    System* s1 = simulator->createSystem("Poblacion", 100.0);
    System* s2 = simulator->createSystem("Recursos", 500.0);

    cout << "Model '" << simulator->getName() << "' loaded into memory." << endl;
    cout << "Registered systems: " << endl;
    
    // Collection traversal abstracts implementation details.
    for(auto it = simulator->systemBegin(); it != simulator->systemEnd(); ++it) {
        cout << "- " << (*it)->getName() << " : " << (*it)->getValue() << endl;
    }

    cout << "\nBase simulation ready to operate. (OK)" << endl;

    // Graceful memory deallocation ensures strict resource lifecycle management.
    delete s1;
    delete s2;
    delete simulator;

    return 0;
}