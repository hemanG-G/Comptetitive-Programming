// problem : https://cses.fi/problemset/task/1648
// simple query and update
// 99% wala seg tree prob


//////////////////////////////my cp template (beta)////////////////////////////////
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//aliases
using ll = long long ;
using ld = long double;
using ull = unsigned long long ;

//constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9 + 7; //1e9+ 7; // modulo answers


// macros
#define trav(a,x)           for (auto& a : x)
#define int                 long long // in time strict problems use int not long long
#define fr                     first
#define sc                     second
#define pii                 pair<int,int>
#define pll                 pair<ll,ll>
#define pb                    push_back
#define ppb                   pop_back
#define pf                   push_front
#define ppf                    pop_front
#define mkp                 make_pair
#define lb                     lower_bound
#define ub                     upper_bound
#define fo(i,a,b)             for(int i=a;i<b;i++)
typedef                     vector<int> vi;
typedef                     vector<ll> vll;
typedef vector<pii>         vpii;
typedef vector<pll>         vpll;
#define sz(x)                 (ll)(x.size())
#define mem1(a)              memset(a,-1,sizeof(a))
#define mem0(a)              memset(a,0,sizeof(a))

//#define all(x)            (x).begin(),(x).end()
//#define uniq(v)           (v).erase(unique(all(v)),(v).end())
//#define getunique(v)         {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}




// operator overloads
template<typename T> // cin >> vector <T>  // auto for loop input
istream& operator>>(istream &istream, vector<T> &v)
{
    for (auto &it : v)
        cin >> it;
    return istream;
}

template<typename T1 , typename T2> // cin >> pair < T1, T2 >
istream& operator>>(istream &istream, pair<T1, T2> &p) {return (istream >> p.first >> p.second); }


template<typename T1 , typename T2> // cout << pair < T1, T2 >
ostream& operator<<(ostream &ostream, const pair<T1, T2> &p) {return (ostream << p.first << p.second); }

template<typename T>
ostream& operator<<(ostream &ostream, const vector<T> &c) {for (auto &it : c) cout << it << " "; return ostream; }


// //pragmas
// #pragma GCC optimize("03, unroll-loops")
// #pragma GCC target("avx2, bmi , bmi2, lzcnt,popcnt")


// utility functions

ll mod(ll x ) {return ((x % MOD + MOD) % MOD);}

int bin_exp(int a , int b , int m  ) { // (a^b )%m
    int ans = 1 ;
    while (b) { // implies b>0
        if (b & 1) {
            ans = ((ans * 1LL * a) % m);
        }
        a = ((a * 1LL * a) % m);
        b = b >> 1;
    }
    return ans;
}

ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}

ll MOD_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}

ll gcd(ll a, ll b) { if (b == 0) return a; return gcd(b, a % b);}

ll LCM (ll a, ll b ) {return ((ll)a * b) / gcd(a, b);}

ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}

ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % MOD; b >>= 1;} return res;}


// shortcuts and SYNTAX
// ALT + SHIFT + F ==  AUTO INDENT CODE
// CTRL + ] == WHOLE CODE LEFT OR RIGHT
// clear all test cases == ctrl + a  +d


/////////////////////////////////STAR CODE HERE!! /////////////////////////////////////////
// from : harisam

#define ll long long
template<class T, class U>
// T -> node, U->update.


// TO DO
// 1) CHANGE COMBINE FN
// 2) CHANGE APPLY FN
// 3) CHANGE COMBINE UPDATE FN

struct Lsegtree {
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;

    /*
        THIS IS HO
        Definition of identity_element: the element I such that combine(x,I) = x
        for all x

        Definition of identity_update: the element I such that apply(x,I) = x
        for all x
    */

    Lsegtree(ll n, T identity_element, U identity_update)
    {
        this->n = n;
        this->identity_element = identity_element;
        this->identity_update = identity_update;
        st.assign(4 * n, identity_element);
        lazy.assign(4 * n, identity_update);
    }


    T combine(T l, T r)
    {
        // change this function as required.
        T ans = (l + r);
        return ans;
    }


    void buildUtil(ll v, ll tl, ll tr, vector<T>&a)
    {
        if (tl == tr)
        {
            st[v] = a[tl];
            return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil(2 * v + 1, tl, tm, a);
        buildUtil(2 * v + 2, tm + 1, tr, a);
        st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
    }



    // change the following 2 functions, and you're more or less done.
    T apply(T curr, U upd, ll tl, ll tr)
    {
        T ans = (tr - tl + 1) * upd;
        // increment range by upd:
        //T ans = curr + (tr - tl + 1)*upd

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        // lazy propogation in segment trees
        // combining  the lazy update with the new update , to update together

        //eg : if update means adding 'x' to the range
        // U ans = old_upd + new_upd



        // the below is case where update means assigning value to a range
        U ans = old_upd;
        ans = new_upd;
        return ans;
    }


    void push_down(ll v, ll tl, ll tr)
    {
        //for the below line to work, make sure the "==" operator is defined for U.
        if (lazy[v] == identity_update)return;
        st[v] = apply(st[v], lazy[v], tl, tr);
        if (2 * v + 1 <= 4 * n)
        {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate(lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate(lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = identity_update;
    }
    T queryUtil(ll v, ll tl, ll tr, ll l, ll r)
    {
        push_down(v, tl, tr);
        if (l > r)return identity_element;
        if (tr < l or tl > r)
        {
            return identity_element;
        }
        if (l <= tl and r >= tr)
        {
            return st[v];
        }
        ll tm = (tl + tr) >> 1;
        return combine(queryUtil(2 * v + 1, tl, tm, l, r), queryUtil(2 * v + 2, tm + 1, tr, l, r));
    }

    void updateUtil(ll v, ll tl, ll tr, ll l, ll r, U upd)
    {
        push_down(v, tl, tr);
        if (tr < l or tl > r)return;
        if (tl >= l and tr <= r)
        {
            lazy[v] = combineUpdate(lazy[v], upd, tl, tr);
            push_down(v, tl, tr);
        }
        else
        {
            ll tm = (tl + tr) >> 1;
            updateUtil(2 * v + 1, tl, tm, l, r, upd);
            updateUtil(2 * v + 2, tm + 1, tr, l, r, upd);
            st[v] = combine(st[2 * v + 1], st[2 * v + 2]);
        }
    }



    void build(vector<T>a)
    {
        assert( (ll)a.size() == n);
        buildUtil(0, 0, n - 1, a);
    }
    T query(ll l, ll r)
    {
        return queryUtil(0, 0, n - 1, l, r);
    }
    void update(ll l, ll r, U upd)
    {
        updateUtil(0, 0, n - 1, l, r, upd);
    }
};


void solve(int tc) {

    int n , q; cin >> n >> q ;

    vector<int> v(n + 1);
    fo(i, 1, n + 1) {
        cin >> v[i];
    }

    Lsegtree <ll, ll> st (n + 1, 0, -1);

    st.build(v);

    fo(i, 0, q) {
        ll type;
        cin >> type;
        if (type == 1 ) {
            int k , u ; cin >> k >> u ;
            st.update(k, k, u);
        }
        else {
            int a, b ; cin >> a >> b ;
            cout << st.query(a, b) << endl;
        }
    }

}

// !!!POSSIBLE ERRORS!!!
// are there edge cases (N=1?)
// are array sizes proper
// integer overflow?
// DS reset properly between test cases



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
