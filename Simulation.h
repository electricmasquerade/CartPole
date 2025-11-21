#pragma once
#include <vector>

#include "CartPoleSystem.h"
#include "Genome.h"


class Simulation {
public:
    Simulation();
    explicit Simulation(const int populationSize, const State state) : size(populationSize), initialState(state) {
        population.resize(size);
    }

    ~Simulation() = default;

    void initialize();
    void runGeneration(float simulationTime, float timeStep);
    void sortByFitness();
    [[nodiscard]] Genome tournament(int tournSize) const;
    void evolvePopulation(float mutationRate, float mutationAmount);

    static Genome crossover(const Genome& parent1, const Genome& parent2);

    [[nodiscard]] float getBestFitness() {
        sortByFitness();
        return population.front().getFitness();
    }

    void setTournamentPercent(const int percent) {
        tournamentPercent = percent;
    }

    void setMaxWeight(const float maxW) {
        maxWeight = maxW;
        for (auto& genome : population) {
            genome.setMaxWeight(maxW);
        }
    }

    [[nodiscard]] std::vector<Genome> getPopulation() const {;
        return population;
    }


private:
    std::vector<Genome> population;
    int size = 100;
    CartPoleSystem cartPoleSystem; //use this and reset to run multiple sims
    State initialState{0.0f, 0.0f, 0.0f, 0.0f};
    int tournamentPercent{3};
    float maxWeight = 1.0f;



};
