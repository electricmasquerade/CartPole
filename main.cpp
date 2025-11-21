#include <iostream>
#include "Cart.h"
#include "Pole.h"
#include "CartPoleSystem.h"
#include "Simulation.h"

int main() {
    constexpr State initialState{0.0f, 0.0f, 0.1f, 0.0f};

    Simulation simulation(100, initialState);



    //test the physics of the system with a simple update
    constexpr float dt = 1.0f/60.0f; // time step of 60 Hz
    constexpr float mutationAmount = 0.2f;
    constexpr float mutationRate = 0.1f;
    constexpr int numGenerations = 1000;
    constexpr float maxWeight = 10.0f;
    simulation.setMaxWeight(maxWeight);

    simulation.initialize();
    for (int i = 0; i < 5; i++) {
        auto genome = simulation.getPopulation()[i].getGenome();
        std::cout << "Genome " << i << ": ";
        for (auto w : genome) std::cout << w << " ";
        std::cout << std::endl;
    }


    //run 10 generations
    for (int generation = 0; generation < numGenerations; ++generation) {
        std::cout << "Generation " << generation << std::endl;
        simulation.runGeneration(30.0f, dt); // run each genome for 20 seconds
        std::cout << "Best fitness: " << simulation.getBestFitness() << std::endl;
        simulation.evolvePopulation(mutationRate, mutationAmount);
    }

    // cartPoleSystem.update(force, dt);
    // currentTime = currentTime + dt;
    // State state = cartPoleSystem.getState();
    // std::cout << "After applying force of " << force << " N for " << dt << " s:" << std::endl;
    // std::cout << "Cart position: " << state.cartPosition << " m" << std::endl;
    // std::cout << "Cart velocity: " << state.cartVelocity << " m/s" << std::endl;
    // std::cout << "Pole angle: " << state.poleAngle << " rad" << std::endl;
    // std::cout << "Pole angular velocity: " << state.poleAngularVelocity << " rad/s" << std::endl;
    // std::cout << std::endl;

    // while (!cartPoleSystem.isFailed()) {
    //     const float new_force = -50 * state.poleAngle - 5 * state.poleAngularVelocity; // simple PD controller
    //     cartPoleSystem.update(new_force, dt);
    //     state = cartPoleSystem.getState();
    //     std::cout << "Time: " << currentTime << " s" << std::endl;
    //     std::cout << "Cart position: " << state.cartPosition << " m" << std::endl;
    //     std::cout << "Cart velocity: " << state.cartVelocity << " m/s" << std::endl;
    //     std::cout << "Pole angle: " << state.poleAngle << " rad" << std::endl;
    //     std::cout << "Pole angular velocity: " << state.poleAngularVelocity << " rad/s" << std::endl;
    //     std::cout << std::endl;
    //     currentTime = currentTime + dt;
    //     if (currentTime > 30.0f) {
    //         std::cout << "Simulation time exceeded 30 seconds, stopping." << std::endl;
    //         break;
    //     }
    // }


    return 0;
}
