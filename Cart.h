#pragma once

// This defines the Cart class for the cart-pole system
class Cart {
public:
    Cart() = default;
    Cart (const float mass, const float initialPosition)
        : mass(mass), position(initialPosition), velocity(0.0f) {}
    ~Cart() = default;

    [[nodiscard]] float getMass () const { return mass; }
    [[nodiscard]] float getPosition () const { return position; }
    [[nodiscard]] float getVelocity () const { return velocity; }

    void setPosition (const float newPosition) { position = newPosition; }
    void setVelocity (const float newVelocity) { velocity = newVelocity; }
    void setMass (const float newMass) { mass = newMass; }


private:
    float mass = 1.0; // Mass of the cart in kg
    float position = 0.0; // Position of the cart on the track, just a 1D coordinate
    float velocity = 0.0; // Velocity of the cart, 1D +/- scalar
};