cmake_minimum_required(VERSION 4.0)
project(CartPole)

set(CMAKE_CXX_STANDARD 20)

add_executable(CartPole main.cpp
        Cart.cpp
        Cart.h
        Pole.cpp
        Pole.h
        CartPoleSystem.cpp
        CartPoleSystem.h
        Genome.cpp
        Genome.h
        Simulation.cpp
        Simulation.h)
