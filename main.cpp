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


    return 0;
}