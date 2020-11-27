#include <iostream>
#include "client.hpp"
#include "adaptee.hpp"

int main(int argc, char *argv[])
{
    Client c;
    c.DoWork(new DefinedInterface);
    // c.DoWork(new Adaptee) // Error: No matched function call
    c.DoWork(new Adapter());    // Actuall call method from Adaptee

    return 0;
}
