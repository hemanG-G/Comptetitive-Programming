#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
using ld = long double;
using ull = unsigned long long ;
constexpr ll MOD = 1e9+ 7;
const char nl = '\n';
//#define int long long
#define ff first
#define ss second
const ld EPS = 1e-9;

#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define sz(X) ((int)(X).size())
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define maxe(v)  *max_element(v.begin(),v.end())     // find max element in vector
#define mine(v)  *min_element(v.begin(),v.end())     // find min element in vector
#define unq(v)  v.resize(distance(v.begin(), unique(v.begin(), v.end()))); // make sure to sort before applying unique // else only consecutive duplicates would be removed
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef vector<vector<ll> > vvll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<ll> vll;
int pwr(int a , int b, int m ) {int ans = 1 ; while (b) { if (b & 1) {ans = ((ans * a) % m);} a = ((a * a) % m); b = b >> 1;} return ans;}
//for modular inverse pwr(to_inv,mod-2,mod)
ll mod(ll x ) {return ((x % MOD + MOD) % MOD);}
ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}
ll mod_divide(int x, int y){return mod_mul(x, pwr(y, MOD - 2,MOD));}
ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}
ll LCM (ll a, ll b ) {return ((ll)a * b) / gcd(a, b);}
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
// alt ceildiv = a+b-1/b;
template<typename typC,typename typD> istream &operator>>(istream &cin,pair<typC,typD> &a) { return cin>>a.first>>a.second; }
template<typename typC> istream &operator>>(istream &cin,vector<typC> &a) { for (auto &x:a) cin>>x; return cin; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const pair<typC,typD> &a) { return cout<<a.first<<' '<<a.second; }
template<typename typC,typename typD> ostream &operator<<(ostream &cout,const vector<pair<typC,typD>> &a) { for (auto &x:a) cout<<x<<'\n'; return cout; }
template<typename typC> ostream &operator<<(ostream &cout,const vector<typC> &a) { int n=a.size(); if (!n) return cout; cout<<a[0]; for (int i=1; i<n; i++) cout<<' '<<a[i]; return cout; }
template<typename T>
void amin(T &a, T b) {
    a = min(a, b);
}
template<typename T>
void amax(T &a, T b) {
    a = max(a, b);
}
#define yes  cout << "YES" << '\n';
#define no  cout << "NO" << '\n';
template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >; 


// int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
// int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
 
//            { U  , D ,  L  , R , UL  , UR  , DL  , DR }




////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  What is better ? To be born good, or to overcome your weakness with great effort ?
// why do we fall bruce ? 



//random number gen  
//random_device seed_gen;
//mt19937_64 engine(seed_gen());
//int random_number_less than 2 ^31=engine()&((1ll<<31)-1);


const ll   N     =  1e7+5;
const ll   INF   =  1e18;
//ll n,m,k,t;
//int a[N],b[N];
// Practice is the only shortcut to improve

const int MAX_SIZE = 1000;
const double PI = 2.0*acos(0.0);
struct PT
{
    double x,y;
    double length() {return sqrt(x*x+y*y);}
    int normalize(){
    // normalize the vector to unit length; return -1 if the vector is 0
        double l = length();
        if(fabs(l)<EPS) return -1;
        x/=l; y/=l;
        return 0;
    }
    PT operator-(PT a){
        PT r;
        r.x=x-a.x; r.y=y-a.y;
        return r;
    }
    PT operator+(PT a){
        PT r;
        r.x=x+a.x; r.y=y+a.y;
        return r;
    }
    PT operator*(double sc){
        PT r;
        r.x=x*sc; r.y=y*sc;
        return r;
    }
};

bool operator<(const PT& a,const PT& b){
    if(fabs(a.x-b.x)<EPS) return a.y<b.y;
    return a.x<b.x;
}
double dist(PT& a, PT& b){
    // the distance between two points
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
double dot(PT& a, PT& b){
    // the inner product of two vectors
    return(a.x*b.x+a.y*b.y);
}
double cross(PT& a, PT& b){
    return(a.x*b.y-a.y*b.x);
}

// =================================================================
// The Convex Hull
// =================================================================

int sideSign(PT& p1,PT& p2,PT& p3){
// which side is p3 to the line p1->p2? returns: 1 left, 0 on, -1 right
    double sg = (p1.x-p3.x)*(p2.y-p3.y)-(p1.y - p3.y)*(p2.x-p3.x);
    if(fabs(sg)<EPS) return 0;
    if(sg>0) return 1;
    return -1;
}

bool better(PT& p1,PT& p2,PT& p3){
    // used by convec hull: from p3, if p1 is better than p2
    double sg = (p1.y - p3.y)*(p2.x-p3.x)-(p1.x-p3.x)*(p2.y-p3.y);
    //watch range of the numbers
    if(fabs(sg)<EPS){
        if(dist(p3,p1)>dist(p3,p2))return true;
        else return false;
    }
    if(sg<0) return true;
    return false;
}

void vex2(vector<PT> vin,vector<PT>& vout){
    // vin is not pass by reference, since we will rotate it
    vout.clear();
    int n=vin.size();
    sort(vin.begin(),vin.end());
    PT stk[MAX_SIZE];
    int pstk, i;
    // hopefully more than 2 points
    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++){
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
        pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=0; i<pstk; i++) vout.push_back(stk[i]);
    // turn 180 degree
    for(i=0; i<n; i++){
        vin[i].y = -vin[i].y;
        vin[i].x = -vin[i].x;
    }
    sort(vin.begin(), vin.end());
    stk[0] = vin[0];
    stk[1] = vin[1];
    pstk = 2;
    for(i=2; i<n; i++){
        if(dist(vin[i], vin[i-1])<EPS) continue;
        while(pstk > 1 && better(vin[i], stk[pstk-1], stk[pstk-2]))
        pstk--;
        stk[pstk] = vin[i];
        pstk++;
    }
    for(i=1; i<pstk-1; i++){
        stk[i].x= -stk[i].x; // don’t forget rotate 180 d back.
        stk[i].y= -stk[i].y;
        vout.push_back(stk[i]);
    }
}

int isConvex(vector<PT>& v){
    // test whether a simple polygon is convex
    // return 0 if not convex, 1 if strictly convex,
    // 2 if convex but there are points unnecesary
    // this function does not work if the polycon is self intersecting
    // in that case, compute the convex hull of v, and see if both have the same area
    int i,j,k;
    int c1=0; int c2=0; int c0=0;
    int n=v.size();
    for(i=0;i<n;i++){
        j=(i+1)%n;
        k=(j+1)%n;
        int s=sideSign(v[i], v[j], v[k]);
        if(s==0) c0++;
        if(s>0) c1++;
        if(s<0) c2++;
    }
    if(c1 && c2) return 0;
    if(c0) return 2;
    return 1;
}

// ===============================================================
// Areas
// ===============================================================
double trap(PT a, PT b){
    // Used in various area functions
    return (0.5*(b.x - a.x)*(b.y + a.y));
}
double area(vector<PT> &vin){
    // Area of a simple polygon, not neccessary convex
    int n = vin.size();
    double ret = 0.0;
    for(int i = 0; i < n; i++) ret += trap(vin[i], vin[(i+1)%n]);
    return fabs(ret);
}
double peri(vector<PT> &vin){
// Perimeter of a simple polygon, not neccessary convex
    int n = vin.size();
    double ret = 0.0;
    for(int i = 0; i < n; i++) ret += dist(vin[i], vin[(i+1)%n]);
    return ret;
    }

double triarea(PT a, PT b, PT c){
    return fabs(trap(a,b)+trap(b,c)+trap(c,a));
    }

double height(PT a, PT b, PT c){
    // height from a to the line bc
    double s3 = dist(c, b);
    double ar=triarea(a,b,c);
    return(2.0*ar/s3);
}

// ====================================================
// Points and Lines
// ====================================================
int intersection( PT p1, PT p2, PT p3, PT p4, PT &r ) {
    // two lines given by p1->p2, p3->p4 r is the intersection point
    // return -1 if two lines are parallel
    double d = (p4.y - p3.y)*(p2.x-p1.x) - (p4.x - p3.x)*(p2.y - p1.y);
    if( fabs( d ) < EPS ) return -1;
    // might need to do something special!!!
    double ua, ub;
    ua = (p4.x - p3.x)*(p1.y-p3.y) - (p4.y-p3.y)*(p1.x-p3.x);
    ua /= d;
    // ub = (p2.x - p1.x)*(p1.y-p3.y) - (p2.y-p1.y)*(p1.x-p3.x);
    //ub /= d;
    r = p1 + (p2-p1)*ua;
    return 0;
}

void closestpt( PT p1, PT p2, PT p3, PT &r ){
    // the closest point on the line p1->p2 to p3
    if( fabs( triarea( p1, p2, p3 ) ) < EPS ) { r = p3; return; }
    PT v = p2-p1;
    v.normalize();
    double pr; // inner product
    pr = (p3.y-p1.y)*v.y + (p3.x-p1.x)*v.x;
    r = p1+v*pr;
}

int hcenter( PT p1, PT p2, PT p3, PT& r ){
    // point generated by altitudes
    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    PT a1, a2;
    closestpt( p2, p3, p1, a1 );
    closestpt( p1, p3, p2, a2 );
    intersection( p1, a1, p2, a2, r );
    return 0;
}
int center( PT p1, PT p2, PT p3, PT& r ){
    // point generated by circumscribed circle
    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    PT a1, a2, b1, b2;
    a1 = (p2+p3)*0.5;
    a2 = (p1+p3)*0.5;
    b1.x = a1.x - (p3.y-p2.y);
    b1.y = a1.y + (p3.x-p2.x);
    b2.x = a2.x - (p3.y-p1.y);
    b2.y = a2.y + (p3.x-p1.x);
    intersection( a1, b1, a2, b2, r );
    return 0;
}

int bcenter( PT p1, PT p2, PT p3, PT& r ){
    // angle bisection
    if( triarea( p1, p2, p3 ) < EPS ) return -1;
    double s1, s2, s3;
    s1 = dist( p2, p3 );
    s2 = dist( p1, p3 );
    s3 = dist( p1, p2 );
    double rt = s2/(s2+s3);
    PT a1,a2;
    a1 = p2*rt+p3*(1.0-rt);
    rt = s1/(s1+s3);
    a2 = p1*rt+p3*(1.0-rt);
    intersection( a1,p1, a2,p2, r );
    return 0;
}

// ===============================================
// Angles
// ===============================================
double angle(PT& p1, PT& p2, PT& p3){
    // angle from p1->p2 to p1->p3, returns -PI to PI
    PT va = p2-p1;
    va.normalize();
    PT vb; vb.x=-va.y; vb.y=va.x;
    PT v = p3-p1;
    double x,y;
    x=dot(v, va);
    y=dot(v, vb);
    return(atan2(y,x));
}

double angle(double a, double b, double c){
    // in a triangle with sides a,b,c, the angle between b and c
    // we do not check if a,b,c is a triangle here
    double cs=(b*b+c*c-a*a)/(2.0*b*c);
    return(acos(cs));
}

void rotate(PT p0, PT p1, double a, PT& r){
    // rotate p1 around p0 clockwise, by angle a
    // don’t pass by reference for p1, so r and p1 can be the same
    p1 = p1-p0;
    r.x = cos(a)*p1.x-sin(a)*p1.y;
    r.y = sin(a)*p1.x+cos(a)*p1.y;
    r = r+p0;
}

void reflect(PT& p1, PT& p2, PT p3, PT& r){
    // p1->p2 line, reflect p3 to get r.
    if(dist(p1, p3)<EPS) {r=p3; return;}
    double a=angle(p1, p2, p3);
    r=p3;
    rotate(p1, r, -2.0*a, r);
}

// ===============================================
// points, lines, and circles
// ===============================================

int pAndSeg(PT& p1, PT& p2, PT& p){
    // the relation of the point p and the segment p1->p2.
    // 1 if point is on the segment; 0 if not on the line; -1 if on the line but not on the segment
    double s=triarea(p, p1, p2);
    if(s>EPS) return(0);
    double sg=(p.x-p1.x)*(p.x-p2.x);
    if(sg>EPS) return(-1);
    sg=(p.y-p1.y)*(p.y-p2.y);
    if(sg>EPS) return(-1);
    return(1);
}

int lineAndCircle(PT& oo, double r, PT& p1, PT& p2, PT& r1, PT& r2){
    // returns -1 if there is no intersection
    // returns 1 if there is only one intersection
    PT m;
    closestpt(p1,p2,oo,m);
    PT v = p2-p1;
    v.normalize();
    double r0=dist(oo, m);
    if(r0>r+EPS) return -1;
    if(fabs(r0-r)<EPS){
        r1=r2=m;
        return 1;
    }
    double dd = sqrt(r*r-r0*r0);
    r1 = m-v*dd; r2 = m+v*dd;
    return 0;
}

int CAndC(PT o1, double r1, PT o2, double r2, PT &q1, PT& q2){

    // intersection of two circles
    // -1 if no intersection or infinite intersection
    // 1 if only one point

    double r=dist(o1,o2);
    if(r1<r2) { swap(o1,o2); swap(r1,r2); }
    if(r<EPS) return(-1);
    if(r>r1+r2+EPS) return(-1);
    if(r<r1-r2-EPS) return(-1);
    PT v = o2-o1; v.normalize();
    q1 = o1+v*r1;
    if(fabs(r-r1-r2)<EPS || fabs(r+r2-r1)<EPS)
    { q2=q1; return(1); }
    double a=angle(r2, r, r1);
    q2=q1;
    rotate(o1, q1, a, q1);
    rotate(o1, q2, -a, q2);
    return 0;
}

int pAndPoly(vector<PT> pv, PT p){
    // the relation of the point and the simple polygon
    // 1 if p is in pv; 0 outside; -1 on the polygon
    int i, j;
    int n=pv.size();
    pv.push_back(pv[0]);
    for(i=0;i<n;i++) if(pAndSeg(pv[i], pv[i+1], p)==1) return(-1);
    for(i=0;i<n;i++) pv[i] = pv[i]-p;
    p.x=p.y=0.0;
    double a, y;
    while(1){
        a=(double)rand()/10000.00;
        j=0;
        for(i=0;i<n;i++){
            rotate(p, pv[i], a, pv[i]);
            if(fabs(pv[i].x)<EPS) j=1;
        }
        if(j==0){
            pv[n]=pv[0];
            j=0;
            for(i=0;i<n;i++) if(pv[i].x*pv[i+1].x < -EPS){
            y=pv[i+1].y-pv[i+1].x*(pv[i].y-pv[i+1].y)/(pv[i].x-pv[i+1].x);
                if(y>0) j++;
            }
            return(j%2);
        }
    }
    return 1;
}

int n;
PT p[N];
int perm[N];
 
void fix(int ind){
    double chk = abs(angle(p[ind+1], p[ind], p[ind+2]));
    if(chk >= PI/2){
        swap(p[ind+1], p[ind+2]);
        swap(perm[ind+1],perm[ind+2]);
    }
}
 
 
 // jus break into smallest 3 point traingles
// intuition : fix current  triplet ,and all triplets before this triplet , which start form i -2 and reduct to zero( the startging poitns)
void solve(int tc) {
    
    cin>>n;
    fo(i,0,n-1){
        int x, y;
        cin>>x>>y;
        p[i].x = x;
        p[i].y = y;
        perm[i] = i;
    }
 
    fo(i,2,n-1){
        for(int j = i-2; j >= 0; j--){
            fix(j);
        }
    }
 
    fo(i,0,n-1) {
        cout<<perm[i]+1<<" ";
    }
    cout<< nl ;
}
// MISSED OBSERVATIONS
//

// PROBLEM TAKEAWAYS:
//
//---------------------------------------------------
// 1) Always use test cases , dont go in blind
// 2) write everything down
// 3) Think Common/Previously Done Techniques
// 4) Dont prove in contest ,just apply pure intuition
// 5) SIMPLEST OBSERVATINO IS MOSTLY THE MOST IMP
/*
#Source : Benq
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph 
*/

/* stuff you should look for
 * int overflow, array bounds
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 */
int32_t main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(12) << fixed;
    int tests = 1;
    // cin >> tests ;   // comment out if no test cases
    for (int tt = 1 ; tt <= tests ; tt++)
    {
        solve(tt);
    }
    return 0;
}





