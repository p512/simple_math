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
