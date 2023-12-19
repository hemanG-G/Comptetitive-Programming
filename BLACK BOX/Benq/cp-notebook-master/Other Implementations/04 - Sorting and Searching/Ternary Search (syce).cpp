// SOURCE : SYCE (16TH SEPT 2023)
//https://cp-algorithms.com/num_methods/ternary_search.html#the-case-of-the-integer-arguments
// more acc , jus do 100 iterations 
double ternary_search(double l, double r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > eps) {
        double m1 = l + (r - l) / 3;
        double m2 = r - (r - l) / 3;
        double f1 = f(m1);      //evaluates the function at m1
        double f2 = f(m2);      //evaluates the function at m2
        if (f1 < f2)// upward parabola here
            l = m1;
        else
            r = m2;
    }
    return f(l);                    //return the maximum of f(x) in [l, r]
}



// on integers
int lo = -1, hi = n;
while (hi - lo > 1){
    int mid = (hi + lo)>>1;
    if (f(mid) > f(mid + 1)) 
         hi = mid;
    else 
         lo = mid; 
}
//lo + 1 is the answer




// sample probs :
// 1)https://codeforces.com/contest/626/problem/E
// 2)https://codeforces.com/problemset/problem/578/C