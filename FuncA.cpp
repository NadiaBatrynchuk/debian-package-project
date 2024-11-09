// FuncA.cpp
#include <cmath>
#include "FuncA.h"

int factorial(int n);

double FuncA::calculate(int n) {
    double sum = 0;
    double x = 1;  // наприклад, оберіть x = 1
    for (int i = 0; i <= n; ++i) {
        double term = pow(x, i) / factorial(i);  // використовуємо x^n / n!
        sum += term;
    }
    return sum;
}

int factorial(int n) {
    return (n == 0 || n == 1) ? 1 : n * factorial(n - 1);
}

