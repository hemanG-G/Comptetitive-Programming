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
	string s; 
	cin>>s;
	int n = s.size();
	
	map<char , vector<int> >  m;
	vector <int> path;
	
	
	for(int i =0 ; i< n  ; i++) {
		m[s[i]].push_back(i+1); // trust the computer to know if u are inputting int or char 
// i said enter this int into map for s[i] as char , so s[i] goes to char , push back int goes to int
	} 
	
	if (s[0] > s[n-1] ) {
		int cost = abs(s[0] -s[n-1]) ; 
		cout << cost << " ";
		for ( int i =0 ; s[0]+i >= s[n-1] ; i-- )  
 // using letters as iteration , like a to z i use  s[0] is a , s[ n-1 ] is z , s[0] + i, i ++  , 
 		{
			char c = s[0] + i ;
			
			//only if we find that letter
			if (m.find(c) != m.end() ) { // m.find reached m.end which is element nex to last element
				
				for ( auto it : m[c]) // itrate the map ,  CONTAINING character c , only , not whole map
					path.PB(it); // so only position in map containging char c , will get push back , it , since char has alr been fixed ,it will go to int of map 
			}
		}


	cout << path.size() << endl; 
	for ( auto it : path){
		cout << it << " " ;
	}
	
	}
	
	
	
	else if ( s[0] < s[n-1])
	{
		int cost = abs(s[0] -s[n-1]) ; 
		cout << cost << " ";
		vector <int> path;
		for ( int i =0 ; s[0]+i <= s[n-1] ; i++ ) 
		{
			char c = s[0] + i ;
			
			//only if we find that letter
			if (m.find(c) != m.end() ) {
				
				for ( auto it : m[c]){
					path.PB(it);
				}
			}
		}

	cout << path.size() << endl; 
	for ( auto it : path){
		cout << it << " " ;
	}

	}
	
	else
	{
		cout << "0" << " " << m[s[0]].size()  << endl; // no of elements contiaing s[0 ] in the map
		for ( auto it : m[s[0]] ){ // iterato to every element of map contaioning s[0]
			cout << it  << " " ; // s[0] is fixed so it iterates the other thing which is  ofcourse int , 
		}
		
	}	
 	
 	
	cout << endl;
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
