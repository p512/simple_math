#define CATCH_CONFIG_MAIN
#include "Catch/include/catch.hpp"
#include "sm.hpp"
#include <cmath>

TEST_CASE("Integral pow", "[pow]" ) {
    for(int i = 1; i < 7; ++i) {
        for(int j = 0; j < 7; ++j) {
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Floating point pow", "[pow]") {
    for(double i = 1; i < 7; i+=0.5) {
        for(float j = 1; j < 7; j+=0.5) {
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Negative integral pow", "[pow]") {
    for(double i = -1; i > -7; --i) {
        for(int j = -1; i > -7; --i) {
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Trignonometric", "[sin][cos]") {
    for(double i = 0; i < 2*M_PI; i+=0.001) {
        REQUIRE( Approx(sm::sin(i)).epsilon(0.0001) == std::sin(i) );
        REQUIRE( Approx(sm::cos(i)).epsilon(0.005) == std::cos(i) );
    }
}

TEST_CASE("e^x", "[exp]") {
    for(double i = 0; i < 10; i+=0.3) {
        REQUIRE( Approx(sm::exp(i)).epsilon((i+1)/1000) == std::exp(i) );
    }
}

TEST_CASE("Natural logarithm", "[log]") {
    for(double i = 0.3; i < 10; i+=0.3) {
        REQUIRE( Approx(sm::log(i)).epsilon(0.05) == std::log(i) );
    }
}

