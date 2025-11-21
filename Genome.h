#pragma once
#include <vector>
#include <random>

// this encodes the genome for linear weights
class Genome {
public:
    Genome()=default;
    Genome(float weight1, float weight2, float weight3, float weight4, float bias);
    ~Genome() = default;

    void randomize();
    void mutate(float mutationRate, float mutationAmount);
    void setFitness(const float fit) { fitness = fit; }
    void setGenome(const std::vector<float>& newGenome) { genome = newGenome; }
    [[nodiscard]] float getFitness() const { return fitness; }

    [[nodiscard]] const std::vector<float>& getGenome() const { return genome; }

private:
    std::vector<float> genome;
    float fitness = 0.0f;
    std::mt19937 rng;


};