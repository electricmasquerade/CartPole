#include "Genome.h"

Genome::Genome(const float weight1, const float weight2, const float weight3, const float weight4, const float bias) {
    genome.push_back(weight1);
    genome.push_back(weight2);
    genome.push_back(weight3);
    genome.push_back(weight4);
    genome.push_back(bias);
}

void Genome::randomize() {
    //fill genome with random weights between -1 and 1
    genome.clear();
    for (int i = 0; i < 5; ++i) {
        float weight = static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 2) - 1.0f; // random float between -1 and 1
        genome.push_back(weight);
    }
}

void Genome::mutate(const float mutationRate, const float mutationAmount) {
    //mutate each weight with a given mutation rate chance
    for (auto& weight : genome) {
        float randVal = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        if (randVal < mutationRate) {
            const float mutation = (static_cast<float>(rand()) / static_cast<float>(RAND_MAX / 2) - 1.0f) * mutationAmount; // random mutation between -mutationAmount and +mutationAmount
            weight += mutation;
            //clamp weight to -1 to 1
            if (weight > 1.0f) weight = 1.0f;
            if (weight < -1.0f) weight = -1.0f;
        }
    }
}
