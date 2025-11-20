#include <iostream>
#include "Cart.h"
#include "Pole.h"
#include "CartPoleSystem.h"

int main() {
    Cart cart(1.0f, 0.0f);
    Pole pole(1.0f, 0.1f, 0.0f);
    CartPoleSystem cartPoleSystem(cart, pole);
    std::cout << "Cart mass: " << cart.getMass() << " kg" << std::endl;
    std::cout << "Pole length: " << pole.getLength() << " m" << std::endl;
    std::cout << "Cart-Pole system initialized." << std::endl;

    //test physics of system with a simple update
    constexpr float force = 1.0f; // apply a force of 10 N to the cart
    constexpr float dt = 1.0/60.0f; // time step of 60Hz
    float currentTime = 0.0f;
    cartPoleSystem.update(force, dt);
    currentTime = currentTime + dt;
    std::vector<float> state = cartPoleSystem.getState();
    std::cout << "After applying force of " << force << " N for " << dt << " s:" << std::endl;
    std::cout << "Cart position: " << state[0] << " m" << std::endl;
    std::cout << "Cart velocity: " << state[1] << " m/s" << std::endl;
    std::cout << "Pole angle: " << state[2] << " rad" << std::endl;
    std::cout << "Pole angular velocity: " << state[3] << " rad/s" << std::endl;
    std::cout << std::endl;

    while (!cartPoleSystem.isFailed()) {
        cartPoleSystem.update(0.0, dt);
        state = cartPoleSystem.getState();
        std::cout << "Time: " << currentTime << " s" << std::endl;
        std::cout << "Cart position: " << state[0] << " m" << std::endl;
        std::cout << "Cart velocity: " << state[1] << " m/s" << std::endl;
        std::cout << "Pole angle: " << state[2] << " rad" << std::endl;
        std::cout << "Pole angular velocity: " << state[3] << " rad/s" << std::endl;
        std::cout << std::endl;
        currentTime = currentTime + dt;
    }


    return 0;
}