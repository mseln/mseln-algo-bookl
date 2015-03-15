// File:    gcd.cpp
// Author:  Magnus Selin
// Updated: 2014-12-07
// Param:   int a, int b
// Returns: Greatest common divider of a and b.

int gcd(int a, int b){
    int t;
    while (b != 0){
        t = b;
        b = a % b;
        a = t;
    }
    return a;
}
