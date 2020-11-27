#ifndef CLIENT_H
#define CLIENT_H

class DefinedInterface
{
public:
    virtual void ShowYourself();
};

class Client
{
public:
    void DoWork(DefinedInterface *);
};

#endif /* CLIENT_H */
