#include "Foo/library.h"

#include <iostream>

void hello() {
    std::cout << "Hello, World!" << std::endl;
}

Adder::Adder(/* args */)
{
    std::cout << "welp I guess this works statically.. \n maybe? " << std::endl;
}

Adder::~Adder()
{
}