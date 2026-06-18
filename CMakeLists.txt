cmake_minimum_required(VERSION 3.10)
project(MyVensim)

# Configure C++ standard and strict debugging flags
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -g")

# Output binaries to the bin/ directory
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)

# Core simulator source files
set(CORE_SRC
    src/systemImpl.cpp
    src/flowImpl.cpp
    src/modelImpl.cpp
    src/modelFactory.cpp
)

# Core simulator shared library
add_library(myvensim SHARED ${CORE_SRC})

# Main product executable
add_executable(simulador src/main.cpp)
target_link_libraries(simulador myvensim)

# Functional tests executable
add_executable(test_funcional 
    test/funcional/main.cpp 
    test/funcional/funcional_tests.cpp 
)
target_link_libraries(test_funcional myvensim)

# Unit tests executable
add_executable(test_unit 
    test/unit/main.cpp 
    test/unit/unit_tests.cpp 
    test/unit/unit_System.cpp 
    test/unit/unit_Flow.cpp 
    test/unit/unit_Model.cpp 
    test/unit/unit_HandleBody.cpp 
)
target_link_libraries(test_unit myvensim)
