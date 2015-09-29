#define CATCH_CONFIG_MAIN
#include "Catch/include/catch.hpp"
#include "sm.hpp"
#include <cmath>
#include <fstream>

TEST_CASE("Integral pow", "[pow]" ) {
    for(int i = 1; i < 7; ++i) {
        for(int j = 0; j < 7; ++j) {
            CAPTURE( i );
            CAPTURE( j );
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Floating point pow", "[pow]") {
    for(double i = 1; i < 7; i+=0.5) {
        for(float j = 1; j < 7; j+=0.5) {
            CAPTURE( i );
            CAPTURE( j ); 
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Negative integral pow", "[pow]") {
    for(double i = -1; i > -7; --i) {
        for(int j = -1; i > -7; --i) {
            CAPTURE( i );
            CAPTURE( j ); 
            REQUIRE( Approx(sm::pow(i,j)) == std::pow(i,j) );
        }
    }
}

TEST_CASE("Trignonometric", "[sin][cos]") {
    for(double i = 0; i < 2*M_PI; i+=0.001) {
        CAPTURE( i );
        REQUIRE( Approx(sm::sin(i)).epsilon(0.0001) == std::sin(i) );
        REQUIRE( Approx(sm::cos(i)).epsilon(0.005) == std::cos(i) );
    }
}

TEST_CASE("e^x", "[exp]") {
    for(double i = 0; i < 10; i+=0.3) {
        CAPTURE( i );
        REQUIRE( Approx(sm::exp(i)).epsilon(0.01) == std::exp(i) );
    }
}

TEST_CASE("Natural logarithm", "[log]") {
    //REQUIRE( sm::log(0) == std::log(0) );
    for(double i = 0.3; i < 10; i+=0.3) {
        CAPTURE( i );
        REQUIRE( Approx(sm::log(i)).epsilon(0.05) == std::log(i) );
    }
}

TEST_CASE("Combined meta test", "[log][exp]") { //currently invalid
    for(double i = 0.3; i < 10; i+=0.3) {
        //TODO: change epsilon
        CAPTURE( i/sm::log(sm::exp(i)) );
        REQUIRE( Approx(sm::log(sm::exp(i))).epsilon(1) == i );
        CAPTURE( i/sm::exp(sm::log(i)) );
        REQUIRE( Approx(sm::exp(sm::log(i))).epsilon(1) == i );
    }
}
