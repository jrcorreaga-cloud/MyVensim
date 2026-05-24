# 1. Versión mínima y nombre del proyecto
cmake_minimum_required(VERSION 3.10)
project(MyVensim)

# 2. Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 3. Configurar la carpeta "bin" como destino automático de los ejecutables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

# ==========================================
# 4. CONSTRUIR EL FRAMEWORK (La Biblioteca)
# ==========================================
# Tomamos todos los archivos .cpp de la carpeta src y creamos una librería estática llamada "vensim_core"
add_library(vensim_core 
    src/system.cpp 
    src/flow.cpp 
    src/model.cpp
)

# ==========================================
# 5. CONSTRUIR LOS TESTS FUNCIONALES
# ==========================================
# Creamos el ejecutable de las pruebas funcionales
add_executable(funcional_tests 
    test/funcional/main.cpp 
    test/funcional/funcional_tests.cpp
)
# Le conectamos la librería de nuestro motor
target_link_libraries(funcional_tests vensim_core)

# ==========================================
# 6. CONSTRUIR LOS TESTS UNITARIOS
# ==========================================
# Creamos el ejecutable de las pruebas unitarias
add_executable(unit_tests 
    test/unit/main.cpp 
    test/unit/unit_tests.cpp
)
# Le conectamos la librería de nuestro motor
target_link_libraries(unit_tests vensim_core)