#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
  
  
  //cses tower of hanoi
  
  void recursive_hanoi(int src , int dest , int aux , int n ) {
  	if ( n <= 0 ) 
  		return ; 
  	
  	
  	// lets trust the fn to do what isay
  	//  i say move n-1 to src to aux
  	recursive_hanoi(src,aux,dest,n-1);
  	//!!!!!!!!########**********these moves are not HAPPENING IN PRACTICAL ,
  	//i have just trusted the fn in my brain , so i dont print anything
  	
  	// now n-1 at aux , 1 at src , 
  	
  	
  	
  	
  	// lets move that 1 largets disc from src to dest 
  	// this is our first TRUE PRACTICAL cmove , so i will print i
	 cout << src << " " <<  dest << endl ;
	 
	 
	 
	 // now imagine the situation , n-1 at aux + nth at dest
	 
	 
	 
	 //now again like 1st step , i trust the function to move n-1 
	 // from aux to dest , trusting is like PMI ezpz
	 recursive_hanoi (aux , dest , src , n-1) 	;
  	
  }
  
  
  
  
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// bs for fast IO
	
	
	int n ; 
	cin >> n ; 
	
	
	cout<< (1<<n) -1 << endl ;						
	recursive_hanoi(1 ,3 , 2 , n );  // 1  is source, 2 is aux ,/..... 
									//  given in qn
	
	return 0;
}