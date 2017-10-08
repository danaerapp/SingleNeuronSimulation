cmake_minimum_required (VERSION 2.6)
project(Neuron)

set(CMAKE_CXX_FLAGS "-O3 -W -Wall -pedantic -std=c++11")
add_executable (neurone Main_neuron.cpp Neuron.hpp Neuron.cpp Constantes.hpp)
