#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<utility>
#include<set>
#include<unordered_set>
#include<list>
#include<iterator>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<bitset>
#include<random>
#include<map>
#include<unordered_map>
#include<stdio.h>
#include<complex>
#include<math.h>
#include<cstring>
#include<chrono>
#include<string>
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




const ll   N     =  1e7+5;
const ll   INF   =  1e18;
//ll n,m,k,t;
//int a[N],b[N];
// Practice is the only shortcut to improve






void solve(int tc) {
    int n ;cin >> n ;
    vi k(n);
    cin>>k;
    
    vi x(n);
    for(int sm = 1 ;sm <= N ; sm++){
        int tmpsm=sm;
        bool ans = true;
        int nxt = 0;
        fo(i,0,n-1){
            x[i]= ceil_div(tmpsm,k[i]);
            nxt+=x[i];
        }
        tmpsm=nxt;
        fo(i,0,n-1){
            if((k[i]*x[i])<= tmpsm){
                ans=false;
                break;
            }
        }
        fo(i,0,n-1){
            if(x[i]<1){
                ans = false;
                break;
                
            }
        }
        if(ans){
            cout << x ;
            cout << nl;
            return;
        }else{
            continue;
        }
    }
   cout <<  -1  << nl;
    

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
    cin >> tests ;   // comment out if no test cases
    for (int tt = 1 ; tt <= tests ; tt++)
    {
        solve(tt);
    }
    return 0;
}





