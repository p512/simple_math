#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include "sm.hpp"

int main(int argc, char **argv) {
    if(argc < 2) {
        puts("Please supply an angle in radians");
        return 1;
    }
    std::cout.precision(15);
    std::cout << sm::pi<1l<<15>() << std::endl; 
    double x;
    std::sscanf(argv[1], "%lf", &x);
    double libm = std::sin(x);
    double libsm = sm::sin(x);     

    double diff = libm - libsm;
    diff = std::abs(diff);
    std::printf("sum: %.30lf\nsin: %.30lf\ndif: %.30lf\n", libsm, libm, diff); 
    return 0;
}
