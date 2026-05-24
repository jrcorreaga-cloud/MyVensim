cmake_minimum_required(VERSION 3.10)
project(MyVensim)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Place all runtime executables in the `bin` directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# Build the core static library from source files
add_library(vensim_core
    src/system.cpp
    src/flow.cpp
    src/model.cpp
)

# Build the functional tests executable and link the core library
add_executable(funcional_tests
    test/funcional/main.cpp
    test/funcional/funcional_tests.cpp
)
target_link_libraries(funcional_tests vensim_core)

# Build the unit tests executable and link the core library
add_executable(unit_tests
    test/unit/main.cpp
    test/unit/unit_tests.cpp
)
target_link_libraries(unit_tests vensim_core)