#pragma once
#include <vector>

#include "CartPoleSystem.h"
#include "Genome.h"


class Simulation {
public:
    Simulation();
    explicit Simulation(const int populationSize, const State state) : size(populationSize), cartPoleSystem(), initialState(state) {
        population.resize(size);


    }

    ~Simulation() = default;

    void initialize();



private:
    std::vector<Genome> population;
    int size = 100;
    CartPoleSystem cartPoleSystem; //use this and reset to run multiple sims
    State initialState{0.0f, 0.0f, 0.0f, 0.0f   };


};
