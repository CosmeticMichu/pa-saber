cmake_minimum_required(VERSION 3.12) #version minima de CMake requerida para correr el programa, sirve para evitar errores de compilacion
project(matplotlibcpp) #nombre del projecto, no tiene que ser el mismo del ejecutable ni el programa (.cpp)
find_package(Python3 COMPONENTS Interpreter Development Numpy) #paquetes usados, Interpreter permite mostrar la grafica con una función, development se usa para los headers, y numpy lo usa matplotlib para graficar
include_directories(${Python3_INCLUDE_DIRS} /home/eariasp/include) #indica el nombre del directorio donde están los directorios que se necesitan (en este caso, matplotlibcpp.h)
add_executable(sine src/plotting.cpp) #se define el nombre del ejecutable y el programa que lo genera (con su respectiva locacion, en caso de no estar en el mismo directorio)
target_link_libraries(sine ${Python3_LIBRARIES}) #relaciona el ejecutable con la locacion de las librerias usadas (estas estan en la carpeta base de Python, por eso el Python3)
