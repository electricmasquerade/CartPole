#include <iostream>
#include "Cart.h"
#include "Pole.h"
#include "CartPoleSystem.h"

int main() {
    Cart cart(1.0f, 0.0f);
    Pole pole(1.0f, 0.1f, 0.0f);
    CartPoleSystem cartPoleSystem(cart, pole);
    cartPoleSystem.initialize(State {0.0f, 0.0f, 0.2f, 0.0f}); // small initial angle
    std::cout << "Cart mass: " << cart.getMass() << " kg" << std::endl;
    std::cout << "Pole length: " << pole.getLength() << " m" << std::endl;
    std::cout << "Cart-Pole system initialized." << std::endl;

    //test the physics of the system with a simple update
    constexpr float force = 0.0f; // apply a force of 10 N to the cart
    constexpr float dt = 1.0f/60.0f; // time step of 60 Hz
    float currentTime = 0.0f;
    cartPoleSystem.update(force, dt);
    currentTime = currentTime + dt;
    State state = cartPoleSystem.getState();
    std::cout << "After applying force of " << force << " N for " << dt << " s:" << std::endl;
    std::cout << "Cart position: " << state.cartPosition << " m" << std::endl;
    std::cout << "Cart velocity: " << state.cartVelocity << " m/s" << std::endl;
    std::cout << "Pole angle: " << state.poleAngle << " rad" << std::endl;
    std::cout << "Pole angular velocity: " << state.poleAngularVelocity << " rad/s" << std::endl;
    std::cout << std::endl;

    while (!cartPoleSystem.isFailed()) {
        const float new_force = -50 * state.poleAngle - 5 * state.poleAngularVelocity; // simple PD controller
        cartPoleSystem.update(new_force, dt);
        state = cartPoleSystem.getState();
        std::cout << "Time: " << currentTime << " s" << std::endl;
        std::cout << "Cart position: " << state.cartPosition << " m" << std::endl;
        std::cout << "Cart velocity: " << state.cartVelocity << " m/s" << std::endl;
        std::cout << "Pole angle: " << state.poleAngle << " rad" << std::endl;
        std::cout << "Pole angular velocity: " << state.poleAngularVelocity << " rad/s" << std::endl;
        std::cout << std::endl;
        currentTime = currentTime + dt;
        if (currentTime > 30.0f) {
            std::cout << "Simulation time exceeded 30 seconds, stopping." << std::endl;
            break;
        }
    }


    return 0;
}