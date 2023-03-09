
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//nth fibo using ca
ll f(ll n ) {
	ll cache[50];
	for(int i =0 ; i< 50 ; i++) {
		cache[i] = -1;
	}
		if ( n < 2 ) {
		return n ;
		}
		
				
		else if ( cache[n] != -1 ){
			return cache[n] ; 
		}
		else { 
			cache[n] = f(n-1) + f(n-2);	
			return cache[n];		
		}
	
}



// ITERATIVE DP
ll it_dp(ll n) {
	ll f[99] = {0} ;
	
	f[0] = 0 ;
	f[1] = 1 ;
	
	for (ll i = 2 /*****/ ; i <= n ; i++ ){
		f[i] = f[i-2] + f[i-1] ;
		
	}	
	
	return f[n];
	
}



	// withot caching
// void solve ( ll n ) {
		
		
// 		f(n)= f(n-1) + f(n-2);
// 		return f(n);
		
		
// 	}
	
	
	
int main () {
	
	
	// solve(n);
	
	cout << it_dp(22) ; 
	
}