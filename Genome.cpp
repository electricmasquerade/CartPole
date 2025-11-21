#include "Genome.h"

Genome::Genome(const float weight1, const float weight2, const float weight3, const float weight4, const float bias) {
    genome.push_back(weight1);
    genome.push_back(weight2);
    genome.push_back(weight3);
    genome.push_back(weight4);
    genome.push_back(bias);


}

void Genome::randomize() {
    //fill the genome with random weights between -1 and 1
    genome.clear();
    std::uniform_real_distribution dist(-max_weight, max_weight);

    for (int i = 0; i < 5; ++i) {

        float weight = dist(rng); // random float between -1 and 1
        genome.push_back(weight);
    }
}

void Genome::mutate(const float mutationRate, const float mutationAmount) {
    //mutate each weight with a given mutation rate chance
    std::uniform_real_distribution randDist(0.0f, 1.0f);  // For mutation chance
    std::uniform_real_distribution mutationDist(-mutationAmount, mutationAmount);  // For mutation size
    for (auto& weight : genome) {

        if (randDist(rng) < mutationRate) {
            const float mutation = mutationDist(rng) * mutationAmount; // random mutation between -mutationAmount and +mutationAmount
            weight += mutation;
            //clamp weight to be between max and min
            if (weight > max_weight) weight = max_weight;
            if (weight < -max_weight) weight = -max_weight;
        }
    }
}
