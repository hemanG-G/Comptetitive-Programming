#include <bits/stdc++.h>
using namespace std;


// code not working
//https://www.youtube.com/watch?v=dFV0gbIdGAU&list=PLqf9emQRQrnKA_EeveiXQj_uP25w8_5qL&index=8

int n , t , q ;
int dp[105][10100];
int xi[101];
// CRUX OF DP == instead of storing n , t , q in diff arrays , 1 dp array

// Q queries
int rec(int level , int left) {
	//pruning // im doing the check here
	if (left < 0) {
		return 0;
	}
	//base case
	if (level == (n + 1)) { // 1 based indexing
		// i have reached n+1 but
		// check following conditions for base case aswell
		if (left == 0) {
			return 1;
		}
		else {
			return 0;
		}
	}
	// cache check
	if (dp[level][left] != -1) {
		return dp[level][left];
	}

	//transitions
	int ans = 0;
	// dont take
	if (rec(level + 1 , left)) {
		ans = 1;
	};
	// take
	if (rec(level + 1, left - xi[level]) ) {
		ans = 1;
	}

	//save and return // return = what qn has asked == exist or not == 1 or zero
	ans = dp[level][left];
	return ans;
}

void printset(int level , int left) { // same as rec funcation just with print stufint f
	// void type

	//base case
	if (level == n + 1) { // 1 based indexing
		return ; // void return nothing
	}

	//transitions

	// CASES
	// dont take
	if (rec(level + 1 , left)) { // dont take
		printset(level + 1 , left); // DONT DO ANYTHING , DONT PRINT, AS  IM NOT TAKING
	};
	// take
	if (rec(level + 1, left - xi[level]) ) { // take
		//if I take == I print
		// BY DP TREE I KNOW TO ONLY PRINT THE TAKE PARTS

		cout << xi[level] << " "; // PRINT
		printset(level + 1, left - xi[level]); // MOVE
	}


}

int main() {

	cin >> n;
	for ( int i = 1 ; i <= n ; i++) {
		cin >> xi[i];
	}
	cin >> q;


	memset(dp, -1, sizeof(dp));  // O(#S i.e no of states) + O(dp)

	// main concept is here == RESETTING only once   O(N*T*Q)****
	// INSTEAD OF RESETTING FOR EACH QUERY    O(N*T + Q)****



	while (q--) {
		cin >> t;
		//rec(1 , t); // 1 indexing

		// print only if it exists
		if (rec(1, t)) {
			printset(1, t);
			cout << endl;
		}
		else {
			cout << "no solution"  << endl;
		}
	}
}