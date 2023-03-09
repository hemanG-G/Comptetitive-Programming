#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long

//apple division using bitmasking

int main ( ) {
	
	int n ; 
	cin >> n;

	vector<int> weights(n) ; 

	for( int i ; i< n ; i++) {
		cin >> weights[i] ;
	} 	
	
	ll ans = 1e18;
	
	for (int mask = 0 ; mask < (1<<n) ; mask ++ ) {
	// this line generates masks for each element in vector
	 	ll sA=0;
	 	ll sB=0;
	 	for(int i =0 ; i < n ; i++) {
	 		if ( mask &(1<<i)){ // this if statements ,if ith positino is 1 or zero in mask
		 		sA += weights[i];		
	 		}
	 		
	 		else {
	 			sB += weights[i];
	 		}
	 		
	 		
	 	} 
	
	ans = min (ans , abs(sA-sB));

	 }
	
	cout << ans ; 
	return 0; 
}


// JUGAAG

// mask&(1<<b ) kya b th position pe 1 hai?