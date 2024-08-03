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
#define int long long
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
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


// recursive lambda functions
// y_combinator from @neal template https://codeforces.com/contest/1553/submission/123849801
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
//template<class Fun> class y_combinator_result {
//     Fun fun_;
// public:
//     template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
//     template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
// };
// template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


 // USAGE: 
//  auto store_result = y_combinator([&](const auto &dfss,const ll cur,const ll p)->void{ 
//     stk.pb(cur);
//     if(cur==dest){
//         resp=stk;
//         return;
//     }
//     for(const auto &v:e[cur])
//         if(v.ff!=p)
//             dfss(v.ff,cur);
//     stk.pop_back();
// });
// store_result(src,-1);//function name


// PRINT CYCLE USING DFS & STACK
 // auto printCycle=[&](const ll src,const ll dest)->void{
//     vi stk;
//     vi resp;
//     auto dfs = y_combinator([&](const auto &dfss,const ll cur,const ll p)->void{
//         stk.pb(cur);
//         if(cur==dest){
//             resp=stk;
//             return;
//         }
//         for(const auto &v:e[cur])
//             if(v.ff!=p)
//                 dfss(v.ff,cur);
//         stk.pop_back();
//     });
//     dfs(src,-1);
//     cout<<sz(resp)<<endl;
//     for(auto x:resp)
//         cout<<x+1<<" ";
//     cout<<endl;
// };
// printCycle(src,dest);
 


// int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
// int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
 
//            { U  , D ,  L  , R , UL  , UR  , DL  , DR }


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


// source :ecnerwala -> easy mod opreations
// syntax : using num = modnum<MOD>;
//            num a;
//            num b;
//            a+=b;
//            a+b;
//            a+1e9+7;
// template <typename T> T mod_inv_in_range(T a, T m) {
//     // assert(0 <= a && a < m);
//     T x = a, y = m;
//     // coeff of a in x and y
//     T vx = 1, vy = 0;
//     while (x) {
//         T k = y / x;
//         y %= x;
//         vy -= k * vx;
//         std::swap(x, y);
//         std::swap(vx, vy);
//     }
//     assert(y == 1);
//     return vy < 0 ? m + vy : vy;
// }


// template <typename T> T mod_inv(T a, T m) {
//     a %= m;
//     a = a < 0 ? a + m : a;
//     return mod_inv_in_range(a, m);
// }

// template <int MOD_> struct modnum {
//     static constexpr int MOD = MOD_;
//     static_assert(MOD_ > 0, "MOD must be positive");

// private:
//     int v;

// public:

//     modnum() : v(0) {}
//     modnum(int64_t v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
//     explicit operator int() const { return v; }
//     friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
//     friend std::istream& operator >> (std::istream& in, modnum& n) { int64_t v_; in >> v_; n = modnum(v_); return in; }

//     friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
//     friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }

//     modnum inv() const {
//         modnum res;
//         res.v = mod_inv_in_range(v, MOD);
//         return res;
//     }
//     friend modnum inv(const modnum& m) { return m.inv(); }
//     modnum neg() const {
//         modnum res;
//         res.v = v ? MOD-v : 0;
//         return res;
//     }
//     friend modnum neg(const modnum& m) { return m.neg(); }

//     modnum operator- () const {
//         return neg();
//     }
//     modnum operator+ () const {
//         return modnum(*this);
//     }

//     modnum& operator ++ () {
//         v ++;
//         if (v == MOD) v = 0;
//         return *this;
//     }
//     modnum& operator -- () {
//         if (v == 0) v = MOD;
//         v --;
//         return *this;
//     }
//     modnum& operator += (const modnum& o) {
//         v -= MOD-o.v;
//         v = (v < 0) ? v + MOD : v;
//         return *this;
//     }
//     modnum& operator -= (const modnum& o) {
//         v -= o.v;
//         v = (v < 0) ? v + MOD : v;
//         return *this;
//     }
//     modnum& operator *= (const modnum& o) {
//         v = int(int64_t(v) * int64_t(o.v) % MOD);
//         return *this;
//     }
//     modnum& operator /= (const modnum& o) {
//         return *this *= o.inv();
//     }

//     friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
//     friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
//     friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
//     friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
//     friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
//     friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
// };




const ll   N     =  1e7+5;
const ll   INF   =  1e18;
//ll n,m,k,t;
//int a[N],b[N];

/*
#Source : Benq
1. Think Greedy
2. Think Brute Force
3. Think solution in reverse order
4. Think DP [ check constraints carefully ]
5. Check base cases for DP and prove solution for Greedy
6. Think Graph 
 * special cases (n=1?)
 * do smth instead of nothing and stay organized
 * WRITE STUFF DOWN
 * DON'T GET STUCK ON ONE APPROACH
 * Always use test cases , dont go in blind
 * Write everything down
 * Think Common/Previously Done Techniques
 * Dont prove in contest ,just apply pure intuition
 * SIMPLEST OBSERVATINO IS MOSTLY THE MOST IMP
 
*/
 // key obs : sum of bal is req , by contribution technique
 
void solve(int tc) {
    // !!!!!!!! EK TU HI NIRANKAR!!!!!!!!!!!!!
    int n ;cin >> n ; 
        string s; cin >> s;  
        
        int bal= 0 ;
        int ans = 0 ;
        string cur ; 
        fo(i,0,n-1){
            if(i%2==0){
                if(bal>0){
                    s[i]=')';
                    bal--;
                }else{
                    s[i]='(';
                    bal++;
                }
            }else{
                if(s[i]=='('){
                    bal++;
                    
                    
                }else{
                    bal--;
                }
            }
            ans+=bal;
            
        }
        // cout << s << nl;
    cout << ans << nl;

    //function<void(int,int)> dfs= [&](vector<int> &a/*params*/)->*return type*{
        
    //};
}
//Test for your own case
//Check for special values (1 in gcd, corner case etc...)



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





