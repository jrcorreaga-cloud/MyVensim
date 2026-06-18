#include "unit_tests.h"
#include "unit_System.h"
#include "unit_Flow.h"
#include "unit_Model.h"
#include "unit_HandleBody.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Starting unit testing suite (Sprint 6)..." << endl;

    run_unit_tests_globals();
    

    run_unit_tests_System();
    run_unit_tests_Flow();
    run_unit_tests_Model();
    run_unit_tests_HandleBody();

    cout << "All unit tests executed successfully. (OK)" << endl;
    
    return 0;
}
