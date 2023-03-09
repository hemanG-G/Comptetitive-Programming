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

int geometricsum( int prime , int exponent) {
	ll numerator = (binexp_iterative(prime, exponent + 1, MOD) - 1 + MOD ) % MOD ;// add mod cuz cannot define -ve modulo
	ll MMIofdenominator = binexp_iterative(prime - 1, MOD - 2, MOD);
	return (numerator * MMIofdenominator ) % MOD;

}

void solve(int tc)
{
	int n;
	cin >> n ; // no of primes
	vector <int> prime(n);
	vector<int>  exponent(n);
	fo(i, 0, n) {
		cin >> prime[i] >> exponent[i];
	}
	ll noofdivisors = 1;

	fo(i, 0, n) {
		noofdivisors = (noofdivisors * (exponent[i] + 1) ) % MOD; // its multiplicative , so multiply no of divisors of EACH PRIME
	}  // modulo each step

	ll sumofdivisors = 1;

	fo(i, 0, n) {
		sumofdivisors = (sumofdivisors * geometricsum(prime[i], exponent[i]) ) % MOD;
	}






	// imp
	ll productofdivisors = 1 ;

	bool oddexponent = false;
	int positionofoddexponent ;

	// marking THE prime THAT has odd exponent
	fo(i, 0, n) {
		if (exponent[i] % 2 == 1) {
			oddexponent = true;
			positionofoddexponent = i;
		}
		// now the position of odd exponent has been marked



		if (oddexponent) { // if  some odd exponent is present
			ll outerexponent = 1 ;
			fo(i, 0, n) {
				if (i == positionofoddexponent) {
					outerexponent = (outerexponent * ((exponent[i] + 1) / 2)) % (MOD - 1); // fermats little therem ETF of LARGE EXPONENET
				}     // multiply cuz S2 is multiplicative
				else {
					outerexponent = (outerexponent * (exponent[i] + 1)) % (MOD - 1); // ###I DONT UNDERSTAND THIS####
				}
			}

			fo(i, 0, n) {
				productofdivisors = ( productofdivisors * binexp_iterative(prime[i], (exponent[i] * outerexponent) % (MOD - 1), MOD) ) % MOD;
				// again multiplicative nature , so mutliply
				// this is also expo so fermats little theroem

			}

		}
		else // no odd exponent present
		{
			ll outerexponent = 1 ;
			fo(i, 0, n) {
				outerexponent =  (outerexponent * (exponent[i] + 1) ) % ( MOD - 1 );

			}
			fo(i, 0, n) {
				productofdivisors = ( productofdivisors * binexp_iterative(prime[i], ((exponent[i] / 2) * outerexponent ) % (MOD - 1 ), MOD) ) % MOD;

			}
		}


	}

	cout << noofdivisors << " " << sumofdivisors << " " << productofdivisors << endl;


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
