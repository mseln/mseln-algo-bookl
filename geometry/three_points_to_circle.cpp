// File:    three_points_to_circle.cpp
// Author:  Magnus Selin 
// Updated: 2014-12-11
// Input:   Three arbitrary points in 2d space.
// Output:  Middle point and radius of the only circle going through the three points.

#include "datastructures/vec3.cpp"
#include "datastructures/homogenous_coord.cpp"

vector<double> three_points_to_circle(vec3<double> v1, vec3<double> v2, vec3<double> v3){
    vec3<double> m1 = (v2 - v1)/2 + v1;
    vec3<double> m2 = (v3 - v2)/2 + v2;

    vec3<double> n1 = vec3<double>(v2[1]-v1[1], -(v2[0]-v1[0]), 1);
    vec3<double> n2 = vec3<double>(v3[1]-v2[1], -(v3[0]-v2[0]), 1);

    vec3<double> a1 = n1 + m1;
    vec3<double> a2 = n2 + m2;

    h<double> h1(m1[0],m1[1],1);
    h<double> h2(a1[0],a1[1],1);
    h<double> h3(m2[0],m2[1],1);
    h<double> h4(a2[0],a2[1],1);
 
    h<double> l1 = h1*h2;
    h<double> l2 = h3*h4;

    h<double> pm = (l1*l2).norm();

    double r = vec3<double>(pm.x-v1[0], pm.y-v1[1], 0).abs();

    vector<double> ret_val;
    ret_val.push_back(pm.x);
    ret_val.push_back(pm.y);
    ret_val.push_back(r);

    printf("%lf %lf %lf\n", pm.x, pm.y, r);

    return ret_val;
}
