#include "Simulation.h"

#include <iostream>
#include <ostream>

Simulation::Simulation() {
    population.resize(size);
}

void Simulation::initialize() {
    //fill population with random genomes
    for (auto& genome : population) {
        genome.randomize();
    }
}

void Simulation::runGeneration(const float simulationTime, const float timeStep) {
    //run one generation of simulations
    for (auto& genome : population) {
        cartPoleSystem.initialize(initialState);
        float currentTime = 0.0f;
        while (currentTime < simulationTime && !cartPoleSystem.isFailed()) {
            auto [cartPosition, cartVelocity, poleAngle, poleAngularVelocity] = cartPoleSystem.getState();
            //compute force using genome weights
            const std::vector<float>& weights = genome.getGenome();
            const float force = weights[0] * cartPosition +
                                weights[1] * cartVelocity +
                                weights[2] * poleAngle +
                                weights[3] * poleAngularVelocity +
                                weights[4];
            cartPoleSystem.update(force, timeStep);
            currentTime += timeStep;
        }
        // calculate fitness based on time survived out of max simulation time
        const float fitness = currentTime / simulationTime;
        genome.setFitness(fitness);
        std::cout << fitness << std::endl;
        std::cout << std::endl;
    }
}