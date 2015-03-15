// File:    vec3.cpp
// Author:  Magnus Selin
// Updated: 2014-12-07
// Description: Class for vectors of arbitrary type.

#include <iostream>
#include <cmath>

template <class T>
class vec3 {
    private:
        T v[3];
    public:
        vec3(){}
        vec3(T a, T b, T c){ 
            v[0] = a; v[1] = b; v[2] = c; 
        }

        T operator[](int i){ return v[i];}
        vec3 operator=(vec3 o){ v[0] = o[0]; v[1] = o[1]; v[2] = o[2]; }
        vec3 operator+(vec3 o){ 
            return vec3(v[0] + o[0], v[1] + o[1], v[2] + o[2]); 
        }
        vec3 operator-(vec3 o){ 
            return vec3(v[0] - o[0], v[1] - o[1], v[2] - o[2]); 
        }
        vec3 operator-(){ 
            return vec3(-v[0], -v[1], -v[2]); 
        }
        double operator*(vec3 o){ 
            return v[0]*o[0] + v[1]*o[1] + v[2]*o[2]; 
        }
        vec3 operator*(double o){ 
            return vec3(v[0]*o, v[1]*o, v[2]*o);
        }
        vec3 operator/(double o){ 
            return vec3(v[0]/o, v[1]/o, v[2]/o);
        }
        vec3 operator%(vec3 o){ 
            return vec3(
                    v[1]*o[2] - v[2]*o[1],
                    v[2]*o[0] - v[0]*o[2], 
                    v[0]*o[1] - v[1]*o[0]); 
        }

        void operator+=(vec3 o){ *this = *this + o; }
        void operator-=(vec3 o){ *this = *this - o; }
        void operator*=(double o){ *this = *this * o; }

        bool operator==(vec3 o){ 
            return v[0] == o[0] and v[1] == o[1] and v[2] == o[2]; 
        }
        bool operator!= (vec3 o){ 
            return !(*this == o); 
        }

        double abs(){ 
            return sqrt(v[0]*v[0] + v[1]*v[1] + v[2]*v[2]); 
        }
        double ang(vec3 o){
            if(*this != vec3(0,0,0) and o != vec3(0,0,0)) 
                return acos((*this * o) / (this->abs()*o.abs()));
            return 0;
        }
        vec3 norm(){ 
            if(*this != vec3(0,0,0)) 
                return (*this) / this->abs();
            return *this;
        }
};

template<typename T> inline std::ostream &operator<<(std::ostream &os, vec3<T> &v){
    os << "(" << v[0] << ", " << v[1] << ", " << v[2] << ")";
    return os;
}

