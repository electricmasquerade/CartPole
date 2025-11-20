#include "CartPoleSystem.h"

void CartPoleSystem::update(const float force, const float dt) {

    //check for failure condition
    if (fabs(pole.getAngle()) > failureAngle) {
        failed = true;
        return;
    }
    // perform one physics time step update

    //1. read current state of cart and pole
    const float x = cart.getPosition();
    const float x_dot = cart.getVelocity();
    const float theta = pole.getAngle();
    const float theta_dot = pole.getAngularVelocity();

    //2. compute accelerations (theta then x)
    const float theta_double_dot = (gravity * sin(theta) + cos(theta) * ((-force - pole.getMass() * pole.getLength() *
        theta_dot * theta_dot * sin(theta))
        / (cart.getMass() + pole.getMass())))
        / (pole.getLength() * (4.0f/3.0f - (pole.getMass() * cos(theta) * cos(theta))
        / (cart.getMass() + pole.getMass())));

    const float x_double_dot = (force + pole.getMass() * pole.getLength() *
        (theta_dot * theta_dot * sin(theta) - theta_double_dot * cos(theta)))
        / (cart.getMass() + pole.getMass());

    //3. compute new velocities using accelerations and Euler integration
    const float new_x_dot = x_dot + x_double_dot * dt;
    const float new_theta_dot = theta_dot + theta_double_dot * dt;

    //4. compute new positions using velocities and Euler integration
    const float new_x = x + new_x_dot * dt;
    const float new_theta = theta + new_theta_dot * dt;

    //5. update cart and pole state
    cart.setPosition(new_x);
    cart.setVelocity(new_x_dot);
    pole.setAngle(new_theta);
    pole.setAngularVelocity(new_theta_dot);

}

void CartPoleSystem::reset() {
    cart.setPosition(0.0f);
    cart.setVelocity(0.0f);
    pole.setAngle(0.0f);
    pole.setAngularVelocity(0.0f);
    failed = false;
}

