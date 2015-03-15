// File:    vec3.cpp
// Author:  Magnus Selin
// Updated: 2014-12-07
// Description: Rational number class

#include "gcd.cpp"
using namespace std;

template<class T>
class Q{
private:
    T p, q;
public:
    Q(){}
    Q(T a, T b){
        p = a; q = b;
        if(q < 0){p = -p; q = -q;}
        if(p == 0) q = 1;
        if(q == 0){
            // Denominator == 0 -> Handle error
            q = 1;
        }
        T g = gcd(p, q);
        p /= g; q /= g;
    }   
    Q operator+(Q a){ return Q(a.p*q + p*a.q, a.q*q); }
    Q operator-(Q a){ return Q(p*a.q - a.p*q, a.q*q); }
    Q operator*(Q a){ return Q(a.p*p, a.q*q); }
    Q operator/(Q a){ return Q(p*a.q, q*a.p); }
    void operator=(Q a){p = a.p;  q = a.q;}
    bool operator==(Q a){
        Q f = *this
        Q s = Q(a.p, a.q);
        return (f.p == s.p and f.q == s.q);
    }
};
