#pragma once

// the pole that balances on the cart
class Pole {
public:
    Pole() = default;
    Pole (const float length, const float mass, const float initialAngle, const float initialAngularVelocity)
        : length(length), mass(mass), angle(initialAngle), angularVelocity(initialAngularVelocity) {}
    ~Pole() = default;

    //getters
    [[nodiscard]] float getLength() const { return length; }
    [[nodiscard]] float getMass() const { return mass; }
    [[nodiscard]] float getAngle() const { return angle; }
    [[nodiscard]] float getAngularVelocity() const { return angularVelocity; }
    //setters
    void setAngle(const float newAngle) { angle = newAngle; }
    void setAngularVelocity(const float newAngularVelocity) { angularVelocity = newAngularVelocity; }
    void setLength(const float newLength) { length = newLength; }
    void setMass(const float newMass) { mass = newMass; }

    void reset() {
        angle = 0.0;
        angularVelocity = 0.0;
    }


private:
    float length = 1.0; // Length of the pole in meters
    float mass = 0.1; // Mass of the pole in kg
    float angle = 0.0; // Angle of the pole from vertical in radians
    float angularVelocity = 0.0; // Angular velocity of the pole in radians per
};