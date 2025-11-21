#include "Simulation.h"

Simulation::Simulation() {
    population.resize(size);
}

void Simulation::initialize() {
    //fill population with random genomes
    for (auto& genome : population) {
        genome.randomize();
    }
}
