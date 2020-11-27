#ifndef ADAPTEE_H
#define ADAPTEE_H

#include "client.hpp"

class DefinedInterface;

class Adaptee
{
public:
    void IdentityMyself();
};

class Adapter : public DefinedInterface
{
public:
    Adapter() : adaptee_() {}

    void ShowYourself() override;

private:
    Adaptee adaptee_;
};

#endif /* ADAPTEE_H */
