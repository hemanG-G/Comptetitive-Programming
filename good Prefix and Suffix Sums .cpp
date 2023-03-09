//       Qpwoeirut And The City– Prefix and Suffix Sums


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
constexpr ll MOD = 998244853; //1e9+ 7; // modulo answers


// macros
// #define int long long // in time strict problems use int not long long
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define pob pop_back
#define mkp make_pair
#define lb lower_bound
#define ub upper_bound
#define fo(i,a,b) for(int i=a;i<b;i++)
typedef vector<int> vi;
typedef vector<ll> vll;
#define sz(x) (ll)x.size()



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
int LCM (int a, int b )
{
	return ((ll)a * b) / __gcd(a, b);
}

ll mod(ll x ) {
	return ((x % MOD + MOD) % MOD);
}

int binexp_iterative(int a , int b , int m  ) { // (a^b )%m
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




// shortcuts and SYNTAX
// ALT + SHIFT + F ==  AUTO INDENT CODE
// CTRL + ] == WHOLE CODE LEFT OR RIGHT
// clear all test cases == ctrl + a  +d


/////////////////////////////////STAR CODE HERE!! /////////////////////////////////////////

void preSolve()
{

}

void solve(int tc)
{
	int n ;
	cin >>  n ;
	vector <ll> h(n + 2 ); // 1 base indexing for easy odd/ even
	vector <ll> cost(n + 2);
	for ( int i = 1 ; i <= n ; i++) {
		cin >>  h[i];
	}
	for ( int i = 1 ; i <= n ; i++) {
		cost[i] =  max( 0ll, max(h[i - 1], h[i + 1]) + 1 - h[i] ) ; // taking max with zero ensures value is always positive
	}

	if (n % 2 == 1 ) { // n is odd
		// simple case , all odd positions
		ll ans = 0 ;
		for ( int i = 2  ; i <= n - 1 ; i += 2) {
			ans += cost[i];
		}
		cout << ans  << endl;
	}

	else    { // n = even
		vector <ll> prefix(n + 2 ); // cost for converting to  cool upto n
		/*WHY THE F DO I NEED N+2 HERE*/        vector <ll> suffix(n + 3); // cost of converting to cool from last to n ;

		for ( int i = 2 ; i <= n - 2 ; i += 2 ) { // ALL EVEN INDICES ONLY  IDK WHY
			prefix[i] = prefix[i - 2] + cost[i];

		}
		for ( int i = n - 1; i >= 3 ; i -= 2) { // ALL ODD INDICES ONLY IDK WHY
			suffix[i] = suffix[i + 2] + cost[i];
		}

		ll ans  =  suffix[3] ; // CASE WHERE ALL ODD  ARE COOL , NO EVEN IS COOL



		// i didnt get this border case bs
		for (int i = 0 ; i <= n - 2  ; i += 2 ) {
			ans = min ( ans , prefix[i] + suffix[i + 3 ]);
		}
		cout << ans << endl;

	}
}


int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;


	preSolve(); // stuff common to all test cases

	int tests = 1;
	cin >> tests ;   // comment out if no test cases
	for (int tt = 1 ; tt <= tests ; tt++)
	{
		solve(tt);
	}

	return 0;
}
