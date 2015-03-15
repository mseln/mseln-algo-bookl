typedef vec2<double> vd2;
bool segment_segment_intersection(vd2 p, vd2 p1, vd2 q, vd2 q1){
    vd2 r = p1 - p;
    vd2 s = q1 - q;
    
    double t = ((q-p)%s)/(r%s);
    double u = ((q-p)%r)/(r%s);

    if(r%s == 0 and (q-p)%r == 0){
        if((0 <= (q-p)*r and (q-p)*r <= r*r) or
           (0 <= (p-q)*s and (p-q)*s <= s*s))
            return true;
            // Collinear overlapping
        else
            return false;
            // Collinear not overlapping
    }
    else if(r%s == 0 and (q-p)%r != 0){
        return false;
        // Parallel
    }
    else if(0 <= t and t <= 1 and 0 <= u and u <= 1){
        return true;
        // Intersecting at p + tr = q + us
    }
    else{
        return false;
        // Neither parallel nor do they not intersect
    }
}

