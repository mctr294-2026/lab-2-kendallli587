#include "roots.hpp"
#include <iostream>
#include <cmath>

// cmake -S . -B build
// cmake --build build --config Debug
// .\build\roots_demo.exe


// Weird tool
// $env:CMAKE_TLS_VERIFY=0; cmake -S . -B build


bool bisection(std::function<double(double)> f,
               double a, double b,
               double *root) {

    if (f(a) * f(b) >= 0) {
        return false; 
    }

    // n: number of iterations
    int n = static_cast<int>(std::ceil(log2((b - a) / 1e-6)));

    double temp;

    for (int i = 0; i < n; i++) {
        temp = (a + b) / 2.0;

        if (f(temp) > 0) {
            b = temp;
        } else {
            a = temp;
        }
    }

    *root = temp;

    return true;
}

bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {

    if (f(a) * f(b) >= 0) {
        return false; 
    }

    double error = 1.0;
    double c;

    while (error > 1e-6) {
        c = a - (f(a) * (b - a)) / (f(b) - f(a));

        if (f(a) * f(c) <= 0) {
            b = c;
        } else {
            a = c;
        }
        
        error = std::abs(f(c));
    }

    *root = c;
    
    
    return true;
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
    // g(x) = f'(x)
    double x1 = 1; // n
    double x2 = 2; // n+1
                        
    while (std::abs(f(x2) - f(x1)) > 1e-6) {
        double temp = x2;

        x2 = x1 - f(x1) / g(x1);
        x1 = temp; // updating value
    }
    
    // If the error is <= 1e-6, then x1 = x2 approximately
    *root = x1;

    return true;
}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {

    double x1 = 1; // Initial guess and n-1
    double x2 = 2; // Initial guess and n
    double x3 = 3; // n+1
                        
    while (std::abs(f(x2) - f(x3)) > 1e-6) {
        double temp2 = x2;
        double temp3 = x3;

        x3 = x2 - f(x2) * (x2 - x1) / (f(x2) - f(x1));
        x1 = temp2;
        x2 = temp3; 
    }
    
    // If the error is <= 1e-6, then x1 = x2 approximately
    *root = x2;

    return true;
}