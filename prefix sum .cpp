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
	int n;
	cin >> n;
	vector<int> v(n) ;
	for ( int i = 0 ; i < n ; i++)
	{
		cin >> v[i] ;
	}
	
	//pre calculation
	// FIRST CALCULATING PREFIX SUM
	vector<int> prefixsum(n) ; 
	 prefixsum[0] =v[0] ;
	for( int i =1 ; i < n ; i++) {
		prefixsum[i]= v[i] + prefixsum[i-1]; 
	}
	int ans = INF ; 
	
	for ( int first = 0; first < n ; first ++)
	{
		int csum =0; // current sum of the current iterating index
		int last = first;
		bool ok =1 ; 
		int reqsum = prefixsum[first]; 
		int nax = first +1 ; // size of the longest segment  ,this line is size of first segment
		
		
		for ( int i = first +1 ; i < n ;i ++) 
		{
			csum += v[i]  ;
			
			if ( csum > reqsum) 
			{
				ok = 0;
				break;
			}
			
			if ( csum == reqsum)
			{	
				csum = 0 ; // reset csum for next segment
				int csize = i - last ;  
				last = i ;
				nax = max(csize,nax) ; // nax currently denotes the first seg size , and csize currently denotes the current segment size , tis way we itertate over all seg sizs and find largest size among them
			}
		}
		
		
		if ( ok  and (csum == 0)){
			ans = min (nax, ans) ; 			
			
		}
		
		
		
	}
	// ans is printed for each first loop , 1 ans is printed
	cout << ans << endl;
	
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
