#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;

lli ex_gcd(lli a, lli b, lli& x, lli& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    lli x1, y1;
    lli d = ex_gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int main() {
     lli x,y,A,B;
    cin>>x>>y;
    const lli g = ex_gcd(abs(x),abs(y),A,B);
    if(g>2){
        cout<<-1<<endl;
        return 0;
    }
    B*=-1;
    if(x<0)
        A*=-1;
    if(y<0)
        B*=-1;
    if(g==1){
        A*=2;
        B*=2;
    }

    // assert(abs(A*x-B*y)==2);
    cout<<B<<" "<<A<<endl;

    //auto dfs= [&](vector<int> &a/*params*/){
    //};
}