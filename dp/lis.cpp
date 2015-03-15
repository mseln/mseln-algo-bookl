// File:    lis.cpp
// Author:  Magnus Selin
// Updated: 2015-03-15
// Param:   vector<int> a
// Returns: vector<int> lis, Longest Increasing Subsequence in a

vi lis(vi a){
    vi lis;     // Longest increasing subsequnece
    vi s;       // s[i] min number of last number in lis of length i
    vi ind;     // Index of s[i] in a
    vi pre;     // Index to previous in subsequence

    s.push_back(a[0]);
    ind.push_back(0);
    pre.resize(a.size(), -1);

    for(int i = 1; i < a.size(); i++){
        // Start by looking at a list of length 1, and then increase by 1 every
        // step. i=1; a[0] is known to be in lis.
        if(a[i] > s[s.size()-1]){
            // Append at end
            s.push_back(a[i]);
            ind.push_back(i);
            pre[i] = ind[ind.size()-2];
        }
        else{
            vii mit = upper_bound(s.begin(), s.end(), a[i]);
            int m = distance(s.begin(), mit);
            // Ex: {1 (3) 5 7 9} <-- 2  :: replace 2 and 3

            s[m] = a[i];
            ind[m] = i;
            pre[i] = ind[m-1]; 
            if(m == 0) pre[i] = -1;
        }
    }

    int i = ind[ind.size()-1];
    while(i != -1){
        lis.push_back(a[i]);
        i = pre[i];
    }
    reverse(lis.begin(), lis.end());

    return lis;
}


