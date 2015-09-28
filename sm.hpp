#include <cmath>
#include <iostream>

namespace sm {
    template<typename T, long n>
    struct fac {
        static constexpr T value = n * fac<T, n-1>::value;
    };

    template<typename T>
    struct fac<T, 0> {
        static constexpr T value = 1;
    };

    template<typename T, long l>
    class facs {
        facs<T, l-1> rest;
        T value;
    public:
        facs() : value(fac<T, l>::value) {}
        template<typename G>
        constexpr long operator[] (G idx) {
            return *(&value-l+idx);
        }
    };

    template<typename T>
    class facs<T, 0> {
        T value;
    public:
        facs() : value(fac<T, 0>::value) {}
    };
    
    template<unsigned long n>
    double pi() {
        double sum = 1;
        for(unsigned int i = 3; i <= n; i+=2) {
            double term = 1.0/i;
            if(i/2 & 1) {
                sum -= term;
            } else {
                sum += term;
            }
        }
        return sum*4;
    }

    template<typename T, typename G>
    constexpr T pow(T b, G e) {
        return e <= 0 ? 1 : b * pow(b, e-1);
    }

    double sin(double x) {
        constexpr int terms = 20; 
        facs<unsigned long, terms> faclist;
        
        double mult = 1;
        if(x >= M_PI) {
            x -= M_PI;
            mult = -1;
        } 
        double sum = x; 
        for(int i = 3; i < terms; i+=2) {
            double term = pow(x,i)/faclist[i];
            if(i/2 & 1)
                sum -= term;
            else
                sum += term;
        }
        return sum *= mult;
    }
}
