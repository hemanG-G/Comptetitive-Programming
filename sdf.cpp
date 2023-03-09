/*Dev Karan Singh Sisodia*/
#include <bits/stdc++.h>
 
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
 
using namespace std;
using namespace __gnu_pbds;
 
#define pyes cout << "YES" << "\n";
#define pno cout << "NO" << "\n";
#define br cout << "\n";
#define ff first
#define ss second
#define pb push_back
#define mod 1000000007
#define MOD 998244353
#define inf 9223372036854775807
#define all(x) (x).begin(),(x).end()
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " -> "; _print(x); cerr << endl;
#else
#define debug(x)
#endif
 
void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
 
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
 
ll ceil_div(ll a, ll b) {return a % b == 0 ? a / b : a / b + 1;}
ll gcd(ll a, ll b){ if (a == 0ll) { return b;} return gcd(b % a, a);}

ll getmod(ll sum){
    return sum % 9;
}

void solve(){
    string s;
    cin >> s;
    ll w, m;
    cin >> w >> m;
    map<ll, pair<ll, ll>> mp;
    for(ll i = 0; i < 9; i++){
        mp[i] = {0, 0};
    }
    ll n = s.size();
    ll sum = 0;
    for(ll i = 0; i < w; i++){
        sum += (s[i] - '0');
    }
    mp[getmod(sum)].ff = 1;
    for(ll i = w; i < n; i++){
        sum += (s[i] - '0');
        sum -= (s[i-w] - '0');
        if(mp[getmod(sum)].ff == 0){
            mp[getmod(sum)].ff = i - w + 2;
        }else if(mp[getmod(sum)].ss == 0){
            mp[getmod(sum)].ss = i - w + 2;
        }
    }
    vector<ll> presum(n, 0);
    for(ll i = 0; i < n; i++){
        if(i == 0){
            presum[i] = s[i] - '0';
        }else{
            presum[i] = presum[i-1] + (s[i] - '0');
        }
    }
    debug(mp)
    while(m--){
        ll l, r, k;
        cin >> l >> r >> k;
        l--;
        r--;
        ll sum = presum[r];
        if(l-1 >= 0){
            sum -= presum[l-1];
        }
        ll b = getmod(sum);
        vector<pair<ll, ll>> vec;
        for(ll a = 0; a < 9; a++){
            for(ll c = 0; c < 9; c++){
                if((a * b + c) % 9 == k){
                    if(a == c){
                        if(mp[a].ss == 0) continue;
                        vec.pb({mp[a].ff, mp[c].ss});
                    }else{
                        if(mp[a].ff == 0 || mp[c].ff == 0) continue;
                        vec.pb({mp[a].ff, mp[c].ff});
                    }
                }
            }
        }
        sort(all(vec));
        if(vec.size() == 0){
            cout << -1 << " " << -1 << endl;
        }else{
            cout << vec[0].ff << " " << vec[0].ss << endl;
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif // ONLINE_JUDGE
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    //code here
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve();
    }
    //end
 
    return 0;
 
}