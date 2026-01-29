#include "roots.hpp"

// cmake -S . -B build
// cmake --build build --config Debug
// .\build\roots_demo.exe

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