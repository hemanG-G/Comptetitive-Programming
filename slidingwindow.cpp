//////////////////////////////my cp template (beta)////////////////////////////////
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//aliases
using ll =long long ;
using ld = long double;
using ull= unsigned long long ;

//constants
constexpr ll INF = 2e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 998244853; //1e9+ 7; // modulo answers


// macros 
#define int long long
#define F first
#define S second
#define pll pair<ll,ll>
#define PB push_back
#define DB pop_back
#define MP make_pair


// operator overloads
template<typename T> // cin >> vector <T>  // auto for loop input
istream& operator>>(istream &istream,vector<T> &v) 
{
	for (auto &it : v)
		cin >> it;
	return istream;
}

template<typename T1 , typename T2> // cin >> pair < T1, T2 >
istream& operator>>(istream &istream, pair<T1,T2> &p){return (istream >> p.first >> p.second); }


template<typename T1 , typename T2> // cout << pair < T1, T2 >
ostream& operator<<(ostream &ostream, const pair<T1,T2> &p){return (ostream << p.first << p.second); }

template<typename T> 
ostream& operator<<(ostream &ostream, const vector<T> &c){for (auto &it : c) cout << it << " "; return ostream; }


// //pragmas
// #pragma GCC optimize("03, unroll-loops")
// #pragma GCC target("avx2, bmi , bmi2, lzcnt,popcnt")


// utility functions
int LCM (int a, int b )
{
	return((ll)a * b) / __gcd(a,b);
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
	cin >> n ;
	int a[n]; 
	
	for (int i =0  ;i <n ;i ++ ){
		cin >> a[i];
	}	

	
	
	cout << distance(a , max_element(a, a+n)) +1 << endl;
}


int32_t main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout << setprecision(12) << fixed;
	
	
	preSolve(); // stuff common to all test cases
	
	int tests = 1;
	cin >> tests ;   // comment out if no test cases
	for (int tt=1 ; tt<=tests ; tt++)
	{
		solve(tt);
	}
	
	return 0;	
}
