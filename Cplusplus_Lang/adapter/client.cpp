#include <iostream>
#include "client.hpp"

void DefinedInterface::ShowYourself()
{
    std::cout << "I'm defined interface" << std::endl;
}

void Client::DoWork(DefinedInterface *foo)
{
    foo->ShowYourself();
}
