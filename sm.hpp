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
    
    template<typename N>
        class kahansum {
            N C, S, Y, T;
            public:
            kahansum(N value) { S = value; C = 0; }
            kahansum() : kahansum(0) {}
            kahansum<N>& operator +=(N value)
            {
                Y = value - C;
                T = S + Y;
                C = (T - S) - Y;
                S = T;
                return *this;
            }
            kahansum<N>& operator -=(N value)
            {
                Y = -value - C;
                T = S + Y;
                C = (T - S) - Y;
                S = T;
                return *this;
            }
            operator N()
            {
                return S;
            }
        };

    template<typename N, N (func)(double x, int i, unsigned long fac), int start, int increment, bool add_x>
        static inline N sum(N x) {
            constexpr int terms = 30; 
            facs<double, terms> faclist;
            kahansum<N> sum(add_x ? x : 0); 
            for(int i = start; i < terms; i+=increment) {
                sum += func(x, i, faclist[i]);
            }
            return (N)sum;
        }

    template<typename T, typename G>
        constexpr 
        typename std::enable_if<std::is_integral<G>::value,T>::type 
        pow(T b, G e) {
            return e == 0 ? 1 : (e & 1 ? (e < 0 ? 1/b : b) : 1) * pow(b, e/2) * pow(b, e/2) ;
        }
    
    template<typename N, typename G>
        constexpr
        typename std::enable_if<!std::is_integral<G>::value,N>::type
        pow(N x, G y) {
            return exp(y * log(x));
        }

    template<typename N>
        static inline N sin_term(N x, int i, unsigned long fac) {
            return (i/2 & 1 ? -1 : 1) * pow(x,i)/fac;
        }

    template<typename N>
        static inline N cos_term(N x, int i, unsigned long fac) {
            return (i/2 & 1 ? -1 : 1) * pow(x,i)/fac;
        }

    template<typename N>
        static inline N exp_term(N x, int i, unsigned long fac) {
            return pow(x,i)/fac;
        }

    template<typename N>
        static inline N log_term1(N x, int i, unsigned long fac) {
            return pow(-1, i + 1) * pow(x - 1, i)/ (N)i ;
        }

    template<typename N>
        static inline N log_term2(N x, int i, unsigned long fac) {
            return pow((x - 1) / x, i) / (N)i;
        }

    template<typename N>
        N sin(N x) {
            N mult = 1;
            if(x >= M_PI) {
                x -= M_PI;
                mult = -1;
            }
            return sum<N, sin_term<N>, 3, 2, true>(x) * mult;
        }

    template<typename N>
        N cos(N x) {
            return sum<N, cos_term<N>, 0, 2, false>(x);
        }

    template<typename N>
        N exp(N x) {
            return sum<N, exp_term<N>, 0, 1, false>(x);
        }

    template<typename N>
        N log(N x) {
            if(x <= 0.5)
                return sum<N, log_term1<N>, 1, 1, false>(x);
            else
                return sum<N, log_term2<N>, 1, 1, false>(x);
        }

}
