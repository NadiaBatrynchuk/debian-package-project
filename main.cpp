// main.cpp
#include <iostream>
#include "FuncA.h"

int main() {
    FuncA func;
    int n = 10;
    std::cout << "FuncA returns: " << func.calculate(n) << std::endl;
    return 0;
}
