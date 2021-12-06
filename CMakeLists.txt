cmake_minimum_required(VERSION 3.21)
project(proyectoEDmapa)

set(CMAKE_CXX_STANDARD 11)

add_executable(proyectoEDmapa main.cpp Arista.cpp Arista.h Vertice.cpp Vertice.h Grafo.cpp Grafo.h Ubicacion.cpp Ubicacion.h TablaHash.cpp TablaHash.h Gestor.cpp Gestor.h Validar.cpp Validar.h)
