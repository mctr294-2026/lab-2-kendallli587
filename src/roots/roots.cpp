#include "roots.hpp"
#include <iostream>
#include <cmath>

bool bisection(std::function<double(double)> f, double a, double b, double *root) {
    // f is some function
    // (a,b) are lower and upper bounds
    
    // n: number of iterations
    int n = static_cast<int>(std::ceil(log2((b - a) / 1e-6)));

    float root;

    for (int i = 0; i < n; i++) {
        float temp = (a + b) / 2;

        if (temp < 0) {
            temp = (temp + b) / 2;
        } else {
            temp = (a + temp) / 2;
        }
    }       
        
    return root;
}

bool regula_falsi(std::function<double(double)> f,
                  double a, double b,
                  double *root) {
    return false;
}

bool newton_raphson(std::function<double(double)> f,
                    std::function<double(double)> g,
                    double a, double b, double c,
                    double *root) {
    return false;
}

bool secant(std::function<double(double)> f,
            double a, double b, double c,
            double *root) {
    return false;
}

