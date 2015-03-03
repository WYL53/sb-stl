
#include <iostream>
#include <vector>
#include <stdio.h>
#include <memory>
#include <tuple>
#include <malloc.h>
#include <list>
#include <vector>

#include "sb_iterator.h"
#include "sb_memory.h"
#include "sb_exception.h"
#include "sb_vector.h"
using namespace sb;
#include <typeinfo>

/*
struct S { // The type has to be polymorphic
    S()
    {
        std::cout << "S" << std::endl;
    }
    ~S()
    {
        std::cout << "~S" << std::endl;
    }

    std::weak_ptr<S> ptr;
};

std::shared_ptr<S> func()
{
    auto ptr = std::make_shared<S>();
    ptr->ptr = ptr;

    return ptr;
}


class A {
public:
    virtual void foo() {
        std::cout << "A :: foo" << std::endl;
    }
};

class B{
public:
    virtual void bar() {
        std::cout << "B :: bar" << std::endl;
    }
};

class C: public B, public A {
public:
    virtual void foo() {
        std::cout << "C :: foo" << std::endl;
    }
    virtual void bar() {
        std::cout << "C :: bar" << std::endl;
    }
};

int main(void)
{

    C * c = new C();

    void *p = (void*)c;
    B *a = (B*)p;
    a->bar();


    return 0;
}*/



int main(void)
{
    vector<int> v;

    //v.push_back(1);


    return 0;
}
