#include "unit_HandleBody.h"
#include <cassert>
#include <iostream>
#include "../../src/systemImpl.h"
#include "../../src/flowImpl.h"
#include "../../src/modelImpl.h"

using namespace std;

void unit_HandleBody_System() {
    cout << "Testing Handle-Body for System..." << endl;
    
    // Reset counters
#ifdef DEBUGING
    numHandleCreated = 0;
    numHandleDeleted = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;
#endif

    {
        // Create a handle
        SystemHandle s1("S1", 10.0);
        assert(numHandleCreated == 1);
        assert(numBodyCreated == 1);
        
        {
            SystemHandle s2 = s1; // Copy constructor
            assert(numHandleCreated == 2); 
            assert(numBodyCreated == 1); // Should NOT create a new body
        }
        assert(numHandleDeleted == 1); 
    }
    assert(numHandleDeleted == 2);
    assert(numBodyDeleted == 1); 
    
    cout << "  - Handle-Body for System passed." << endl;
}

void unit_HandleBody_Counters() {
    cout << "Testing Handle-Body creation and deletion counters..." << endl;
    
#ifdef DEBUGING
    numHandleCreated = 0;
    numHandleDeleted = 0;
    numBodyCreated = 0;
    numBodyDeleted = 0;

    {
        SystemHandle s1("S1", 10.0);
        SystemHandle s2("S2", 20.0);
        SystemHandle s3 = s1; 
    }

    assert(numHandleCreated == 3);
    assert(numHandleDeleted == 3);
    assert(numBodyCreated == 2);
    assert(numBodyDeleted == 2);
#endif
    cout << "  - Handle-Body counters passed." << endl;
}

void run_unit_tests_HandleBody() {
    unit_HandleBody_System();
    unit_HandleBody_Counters();
}
