#include <iostream>
#include <sstream>
#include <cmath>
#include "sm.hpp"

int main(int argc, char **argv) {
    double count = 1000;
    if(argc > 1) {
        std::stringstream ss(argv[1]);
        ss >> count;
    }
    double step = 2*M_PI/count;
    double sum = 0;
    sm::kahansum<double> sum_k;
    for(double i = 0; i <= 2*M_PI; i += step) {
        double val = std::abs(sm::sin(i)-std::sin(i));
        sum += val;
        sum_k += val;
    }

    std::cout.precision(30);
    std::cout << sum << std::endl;
    std::cout << (double)sum_k << std::endl;
    return 0;
}
