#include <iostream>
#include "adaptee.hpp"

void Adaptee::IdentityMyself()
{
    std::cout << "I'm adaptee" << std::endl;
}

void Adapter::ShowYourself()
{
    adaptee_.IdentityMyself();
}
