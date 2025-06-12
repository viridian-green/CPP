#ifndef BASE_H
# define BASE_H

#include <random>
#include <iostream>

class Base
{
    public:
    virtual ~Base();
    static Base * generate(void);
    void identify(Base* p);
    void identify(Base& p);
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

#endif