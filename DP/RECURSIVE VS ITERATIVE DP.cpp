#include<iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


// NTH FIBO USING CACHEING + RECURSOIN

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
			cache[n] = f(n-1) + f(n-2);	  // RECURSION
			return cache[n];		
		}
	
}

	// withot caching
// void solve ( ll n ) {
		
		
// 		f(n)= f(n-1) + f(n-2);
// 		return f(n);
		
		
// 	}
	
	
	
int main () {
	
	
	// solve(n);
	
	cout << f(22) ; 
	
}
	
		
	
	

