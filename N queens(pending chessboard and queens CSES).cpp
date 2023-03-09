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
#define fo(i,a,b) for(i=a;i<b;i++)
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

int binexp_iterative(int a , int b , int m  ) {
	int ans = 1 ;
	while (b) { // implies b>0
		if (b & 1) {
			ans = ((ans * a) % m);
		}
		a = ((a * a) % m);
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
// global
int n = 8 ; // define here input later
int queen[8]; // array of rows as index ,storing positon of queen in that row
dp[];


bool check(int row , int colnm ) {

	for ( int i = 0 ; i  <  row ; i++) {
		int previous_row = i;
		int previous_column = queen[i];

		if (previous_column == colnm || abs(previous_column - colnm) == abs(previous_row - row)) {
			return 0;
		}
	}
	return 1;
}






int rec(int level) { // level = row im at

	// base case
	if (level == n) {
		return 1;
	}

	int ans = 0 ;
	for ( int col = 0 ; col < n ; col++) { // each level(row) i have 'n choices
		if (check(level, col)  ) {
			// now move
			//place queen at valid posistion
			queen[level] = col;


			// now move to next valid checked iteration
			ans += rec(level + 1);

			// before going to next column , removing value of previously placed queen

			queen[level] = -1 ;
		}
	}

	return  ans ;	// return statemetn = no of ways of placing from level to N

}


void solve(int tc)
{
	memset(queen, -1, sizeof(queen));

	cout << rec(0) << endl;

}


int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;


	preSolve(); // stuff common to all test cases

	int tests = 1;
	// cin >> tests ;   // comment out if no test cases
	for (int tt = 1 ; tt <= tests ; tt++)
	{
		solve(tt);
	}


	return 0;
}
