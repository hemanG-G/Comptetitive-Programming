#include <bits/stdc++.h>
using namespace std;

int dp[1001];


int rec(int x ) { // returns == 1 or 0 == win or loss when x is left

	//pruning

	// basecase
	if ( x == 0 ) {
		return 0; //  ****BY DEFAULT WE ASSUME WE LOST IN ALL GAME DP PROBLEMS******
	}

	//cache check
	if (dp[x] != -1) {
		return dp[x];
	}

	//transitions or compute
	int ans = 0;  // ****BY DEFAULT WE ASSUME WE LOST IN ALL GAME DP PROBLEMS******

	// checking all cases dp(x-1) , dp(x-2) , dp(x-4) .. dp (x - 2^m)
	for ( int m = 0 ; (1 << m) <= x ; m++) {
		// by default , im in losing state == all WINS
		// if any lOSS = im in winning stae
		if (rec(x - (1 << m) )  == 0  ) {
			ans = 1;
			break;
		}
	}


	//save and return

	return dp[x] = ans;

}


int main () {

	memset(dp , -1 , sizeof(dp));

	for ( int i = 0 ; i <= 20 ; i++) {
		cout <<  i << " " << rec(i) << endl;
	}

}

// GAME DP PROBLEMS MOSTLY HAVE  PATTERN

// OPTIMIZATIONS USING PATTERNS