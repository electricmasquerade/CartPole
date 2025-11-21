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
        const float fitness = currentTime;// / simulationTime;
        genome.setFitness(fitness);
        cartPoleSystem.reset();
        //std::cout << fitness << std::endl;
        //std::cout << std::endl;
    }
}

void Simulation::sortByFitness() {
    //top fitness first
    std::ranges::sort(population, [](const Genome& a, const Genome& b) {
        return a.getFitness() > b.getFitness();
    });
}

Genome Simulation::tournament(const int tournSize) const {
    //return top genome from tournament selection
    std::vector<Genome> tournamentGenomes;
    //tournamentGenomes.resize(tournamentSize);
    //randomly select genomes for the tournament
    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution dist(0, size - 1);
    for (int i = 0; i < tournSize; ++i) {
        const int index = dist(rng);
        tournamentGenomes.push_back(population[index]);
    }
    //find the best genome in the tournament
    Genome bestGenome = tournamentGenomes[0];
    for (const auto& genome : tournamentGenomes) {
        if (genome.getFitness() > bestGenome.getFitness()) {
            bestGenome = genome;
        }
    }
    return bestGenome;

}

void Simulation::evolvePopulation(const float mutationRate, const float mutationAmount) {
    const int tournamentSize = size * tournamentPercent / 100;
    sortByFitness();
    std::vector<Genome> newPopulation;
    newPopulation.reserve(size);
    //directly add top 10% to new population
    for (int i = 0; i < numElites; ++i) {
        newPopulation.push_back(population[i]);
    }
    //fill rest of population with crossover and mutation based on tournament selection
    while (newPopulation.size() < population.size()) {
        Genome parent1 = tournament(tournamentSize);
        Genome parent2 = tournament(tournamentSize);
        Genome offspring = crossover(parent1, parent2);
        offspring.mutate(mutationRate, mutationAmount);
        offspring.setMaxWeight(maxWeight);
        newPopulation.push_back(offspring);
    }
    population = newPopulation;
}


Genome Simulation::crossover(const Genome &parent1, const Genome &parent2) {
    Genome offspring;
    const std::vector<float>& genome1 = parent1.getGenome();
    const std::vector<float>& genome2 = parent2.getGenome();
    std::vector<float> newGenome;
    //linear crossover with weight 0.5
    for (size_t i = 0; i < genome1.size(); ++i) {
        const float newWeight = 0.5f * genome1[i] + 0.5f * genome2[i];
        newGenome.push_back(newWeight);
    }
    //set offspring genome
    offspring.setGenome(newGenome);
    offspring.setFitness(0.0f);



    return offspring;
}
