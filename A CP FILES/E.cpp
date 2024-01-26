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

//#include "ext/pb_ds/assoc_container.hpp"
//#include "ext/pb_ds/tree_policy.hpp" 
//using namespace __gnu_pbds;
//template<class T>
//using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> ;
 
//template<class key, class value, class cmp = std::less<key>>
//using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order(k)  returns iterator to kth element starting from 0; ( it essentially gives the POINTER TO element which has k elements to its left in ordered set)
// order_of_key(k) returns count of elements strictly smaller than k;


const ll   N     =  1e7+5;
const ll   INF   =  1e7;
//ll n,m,k,t;
//int a[N],b[N];
// Practice is the only shortcut to improve

vector<int> cntC;

int getCnt(int l, int r) {
    return cntC[r] - cntC[l];
}

vector< vector<int> > segs; // cnt(l,r,d) - cnt(l,r,c) for each FIXED d 
vector<int> lst;

int maxSegment( vector<int> &s) { // MAXIMUM SEGMENT OF L,R where maximum 1's and minimum subtractions (-Cnt C)
    int mx = -INF;
    
    int bal = 0;
    fo(i, 0, sz(s)-1) {
        bal = max(0, bal + s[i]);
        mx = max(mx, bal);
    }
    return mx;
}


// key obs ans = cnt c (0,n-1) + max(cntD(l,r) - cntC(l,r));

void solve(int tc) {
    int n ,c ;cin >> n >> c;
    vi a(n);
    cin >> a; 
    
    cntC.assign(n + 1, 0);
    fo(i, 0, n-1)
        cntC[i + 1] = cntC[i] + (a[i] == c);
    
    int possD = *max_element(a.begin(), a.end()) + 1; // ALL POSSIBLE D
    segs.assign(possD, vector<int>());
    lst.assign(possD, -1);
    
    // for each d , storing all segments ka -> 1) c count 2) d count
    fo(i, 0, n-1) {
        segs[a[i]].push_back(-getCnt(lst[a[i]] + 1, i)); // - Ccount
        lst[a[i]] = i;
        segs[a[i]].push_back(1);// + dcount
    }
    fo(v, 0, possD-1)
        segs[v].push_back(-getCnt(lst[v] + 1, n)); // -Ccount
        
        
        
        
    int ans = 0;
    fo(v, 0, possD-1) {
        if(v == c) continue; // covered alr
        ans = max(ans, maxSegment(segs[v]));
    }
    
    cout << getCnt(0, n) + ans << endl;


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





