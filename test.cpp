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
