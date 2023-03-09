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
#define int long long
#define F first
#define S second
#define pll pair<ll,ll>
#define PB push_back
#define DB pop_back
#define MP make_pair


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



// shortcuts and SYNTAX
// ALT + SHIFT + F ==  AUTO INDENT CODE
// CTRL + ] == WHOLE CODE LEFT OR RIGHT
// clear all test cases == ctrl + a  +d


/////////////////////////////////STAR CODE HERE!! /////////////////////////////////////////

void preSolve()
{

}
int partition(int *a , int s, int e ) { // *a for pass by reference
	int i = s - 1;
	for (int j = s ; j < e ; j++ ) {
		if (a[j] <= a[e]) {
			i++;
			swap ( a[i] , a[j]);
		}
	}
	swap (a[e], a[i + 1]);

	return i + 1;

}


void recursion_quickSort( int *a , int s , int e) {
	//base case
	if (s >= e) {
		return ;
	}

	//recursive calls
	//first we partition as u know the algo
	// and i watn partitiona fn to return index
	int index = partition(a , s, e );
	// now i have partitinoaed into two segments
	// now i will trust recursion to solve the rest same way
	//recursive call

	// at this point im at the point where , pivot in between , and left and right segmets to it
	//  now recursion will repeat the above steps for me , for segment 1 and segment 2 using recursion.
	recursion_quickSort(a , s, index - 1);
	recursion_quickSort( a, index + 1 , e );
}
void solve(int tc)
{
	int a[] = {2, 3, 1, 11, 7, 8, 4, 10};
	int n = sizeof(a) / sizeof(int);
	recursion_quickSort( a , 0 , n - 1);
	// start , end must be as paramaters as they change with each iteration of recursion
	for ( int i = 0 ; i < n ; i++ ) {
		cout << a[i] << " ";
	}
	return;
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
