#include "funcional_tests.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Executing Functional Tests" << endl;
    
    exponentialFuncionalTest();
    logisticalFuncionalTest();
    complexFuncionalTest();

    cout << "\nAll functional tests passed successfully. (OK)" << endl;
    
    return 0;
}
