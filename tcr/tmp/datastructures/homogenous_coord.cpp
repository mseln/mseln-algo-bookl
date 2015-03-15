template <class T>
class h{ 
    public:
        T x, y, z;
        h(T a, T b, T c){x=a; y=b; z=c;}
        h(T a, T d1, T b, T d2, T c){x=a*d2; y=b*d1; z=c*d1*d2;}
        h(){}

        h<T> operator*(h o){ return h<T>(y*o.z-o.y*z, z*o.x-o.z*x, o.x*y-x*o.y);}

        h<T> norm(){
            if(z!=0){
                if(x/z * z != x or y/z * z != y){
                    int g = gcd(x, gcd(y,z));
                    return h<T>(x/g, y/g, z/g); 
                }
                else return h<T>(x/z, y/z, 1); 
            }
            return h<T>(1,1,0);
        }
};
