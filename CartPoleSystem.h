#pragma once

#include <vector>

#include "Cart.h"
#include "Pole.h"


class CartPoleSystem {
public:
    CartPoleSystem();
    CartPoleSystem(Cart& cart, Pole& pole)
        : cart(cart), pole(pole) {}
    ~CartPoleSystem() = default;

    // getters, only use for viewing, do not
    [[nodiscard]] Cart& getCart() const { return cart; }
    [[nodiscard]] Pole& getPole() const { return pole; }
    [[nodiscard]] bool isFailed() const { return failed; }
    // simulation methods
    [[nodiscard]] std::vector<float> getState() const{
        return {cart.getPosition(), cart.getVelocity(), pole.getAngle(), pole.getAngularVelocity()};
    }

    //setters
    void setFailureAngle(const float angleDegrees) {
        failureAngle = angleDegrees * PI / 180.0f;
    }
    void fail() {
        failed = true;
    }


    void update(float force, float dt);
    void reset();


private:
    Cart& cart;
    Pole& pole;
    bool failed = false;
    const float gravity = 9.81f; // gravitational acceleration in m/s^2
    const float PI = 3.14159f;
    float failureAngle = 12.0f * PI / 180.0f; // failure angle in radians (12 degrees)
};