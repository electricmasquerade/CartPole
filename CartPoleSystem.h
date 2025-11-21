#pragma once


#include "Cart.h"
#include "Pole.h"

struct State {
    float cartPosition;
    float cartVelocity;
    float poleAngle;
    float poleAngularVelocity;
};

class CartPoleSystem {
public:
    CartPoleSystem() {
        //create default cart and pole
        cart = Cart(1.0f, 0.0f);
        pole = Pole(0.1f, 0.5f, 0.0f, 0.0f);
    };
    CartPoleSystem(const Cart& cart, const Pole& pole)
        : cart(cart), pole(pole) {}
    ~CartPoleSystem() = default;

    // getters, only use for viewing, do not
    //[[nodiscard]] Cart& getCart() const { return cart; }
    //[[nodiscard]] Pole& getPole() const { return pole; }
    [[nodiscard]] bool isFailed() const { return failed; }
    // simulation methods
    [[nodiscard]] State getState() const{
        return {cart.getPosition(), cart.getVelocity(), pole.getAngle(), pole.getAngularVelocity()};
    }

    //setters
    void setFailureAngle(const float angleDegrees) {
        failureAngle = angleDegrees * PI / 180.0f;
    }
    void fail() {
        failed = true;
    }

    void initialize(State state);
    void update(float force, float dt);
    void reset();


private:
    Cart cart;
    Pole pole;
    bool failed = false;
    const float gravity = 9.81f; // gravitational acceleration in m/s^2
    const float PI = 3.14159f;
    float failureAngle = 12.0f * PI / 180.0f; // failure angle in radians (12 degrees)
};