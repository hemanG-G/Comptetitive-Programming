#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long 


	// repetetions cses

//  // idk why this dosent work
// int main () {
// 	char a[999] ;
// 	cin.getline(a , 999 ) ;
	
// 	int freq[26] = {0};
	
// 	for (int i=0; i != '\0' ; i++) {
// 		freq[a[i] - 'a'] ++;
// 	}
		
// 	int ans= INT_MIN ;	
// 	for (int j =0; j < 26; j++  ) {
// 		ans = max(ans,freq[j]);
			
	
// 	}
	
// 	cout << ans ;
	
	
// 	return 0; 
// }


// kinda recursive approach
int main () {
	string s ; 
	cin >> s ;
	char l = 'A' ;
	int c = 0;
	int ans =INT_MIN ; 
	
	for( char i : s) 
		if (l==i) {
			c++;
			ans = max( ans , c);
		}
		
		else {
			l=i;
			c=1;
		}
		
		
	
	
	cout << ans;
	
}