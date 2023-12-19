//problem : https://cses.fi/problemset/task/1735
//sum query
// two different types of updates 
// (1% wala seg tree prob)



#include <iostream>
#include <bits/stdc++.h>
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
// from : harisam
// T -> nature of node, U->nature of update.
// 99% cases both integers

// TO DO
// 1) CHANGE COMBINE FN
// 2) CHANGE APPLY FN
// 3) CHANGE COMBINE UPDATE FN
//  use identity element or identiy update if required

// NOTE:
//  size of array and seg tree must be same
// use 1 based indexing


struct update{
    ll setval;
    ll increment;
    // first set to setval , then increment 
    update(){
        setval = -1 ; 
        increment = 0  ;
        
    }
    update(ll setval,ll increment){
        this->setval=setval; 
        this->increment=increment;
        
    }
    
    // 4) defining == operator
    bool operator==(const update& other) const{ // defining equality as both setval and increment have to be equal
        return setval == other.setval && increment == other.increment;
    }
    
};

template<class T, class U>
struct Lsegtree {
    vector<T>st;
    vector<U>lazy;
    ll n;
    T identity_element;
    U identity_update;
    /*  THIS IS HOW YOU USE IDENTIY ELEMENT AND IDENTY UPDATE
        Definition of identity_element: the element I such that combine(x,I) function = x
        for all x
        //eg QUERY for
        // max ::  T = -inf
        // sum ::  T =  0 
        Definition of identity_update: the element I such that apply(x,I) function = x
        for all x
        // eg: UPDATE : add element to range 
        //  U = 0  ; (add 0 , no change )
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
        //QUERY PART
        
        // COMBINE TWO NODES
        // the funcation of what        
        // eg : for max
        // T ans = max(l,r);
        // T ans = min(l,r);
        // T ans = gcd(l,r);
        T ans = (l + r); // SUM QUERY
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
        // APPLY UPDATE TO NODE
        // what you are querying is what needs to be stored in ans
        T ans; 
        ans = curr;
        
        if(upd.setval!=-1){ // have to set too 
            ans = (tr-tl+1)*(upd.setval + upd.increment); //set and incrmenet
            
        }
        else{ // dont hvae to set , jus incrment
            ans +=(tr - tl +1 )*upd.increment; // set to curr ,then incrment
        }
        // this is just updating values of range to upd    
        // eg1 : querying for sum ? 
        // ans stores the new sum
        // T ans = (tr - tl + 1) * upd;

        // eg2 : increment range by upd:
        //T ans = curr + (tr - tl + 1)*upd
        
        // eg3: querying for max
        // ans stores the max
        // T ans = upd;

        return ans;
    }

    U combineUpdate(U old_upd, U new_upd, ll tl, ll tr)
    {
        // lazy propogation in segment trees
        // AT A NODE combining  lazy update with the new update 

        // the below is case where update means assigning  new value to a range , so old upd useless
        U ans ;
        if(new_upd.setval == -1){ // dont need to set ans, just increment ans
            ans = old_upd;
            ans.increment+=new_upd.increment; // only increment
            // ans.setval=new_upd.setval
        }
        else{
            ans = new_upd; //SET AND INCRMENET, SO THE WHOLE NEW
        }
        // ans = new_upd;
         
        //eg : if update means adding 'x' to the range
        // U ans = old_upd + new_upd

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



const ll   N     =  1e7+5;
const ll   INF   =  1e18;
//ll n,m,k,t;
//int a[N],b[N];
void solve(int tc) {
    int n  ;cin >> n ; 
    int q ; cin >> q;
    vi a(n+1,0);
    fo(i,1,n){
        cin>>a[i];
    }
    update idupdate(-1,0);
    Lsegtree<ll,update>st(n+1,0,idupdate);
    st.build(a);
    fo(i,0,q-1){
        int k ; cin >>  k;
    if(k==1){
        int l , r , x; cin >> l >> r >> x ; 
        // l-- ; r--;
        update upd(-1,x);
        st.update(l,r,upd);
    }
    else if (k==2){
        int l , r , x; cin >> l >> r >> x ;
         // l-- ;r--;
        update updd(x,0);
        st.update(l,r,updd);
    }
    else{
        int l , r ; cin >> l >> r  ; 
        // l-- ;r--;
        cout << st.query(l,r) << nl;
    }
    }

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





