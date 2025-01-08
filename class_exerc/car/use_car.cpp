#include <iostream>
#include <stdexcept>
#include "singleton_car.hpp"



void test_car(void) 
{
    car* shelby_1 = car::get_car("Shelby american",
           "Shelby cobra",
           1962,
           "Manual",
           "Steel dual",
           "406 hp",
            259.104,
            10
            );
    std::cout << "First car of car class is created " << std::endl;

    shelby_1->show();
    try {
        car* shelby_2 = car::get_car(
            "Shelby american and ford",
           "Shelby Super Snake",
           2024,
           "Manual",
           "Steel dual",
           "825+ hp",
            259.104,
            1
        );
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    delete shelby_1;
    shelby_1 = 0;
}

int main(void) 
{
    test_car();

    return (0);
}