#include <bits/stdc++.h>
using namespace std;
int n  ;
int lt[1001]; // size of rod array
int dp[1001][1001];


// INTERVAL DP

// ROD CUTTING PROBLEM // O(n^3)
int rec(int l , int r) { // return == minimum cost of cutting rod into n pieces , in l..to..r

	// pruning

	// basecase
	if ( l + 1 == r) { // size of rod left is 1
		return 0 ; // counting problem  invalid case
	}

	// cache check
	if (dp[l][r] != -1) {
		return dp[l][r];
	}


	// transistions or compute
	int ans = 1e9 ; // *****default value of MINIMIZATION PROBLEM


	// loop p(the position of cut) over all l to r and find minimum
	for (int p = l + 1 ; p <= r - 1; p++) {
		ans = min(ans , lt[r] - lt[l] + rec(l, p) + rec(p, r) );
	}


	//save and return
	ans = dp[l][r];
	return ans;
}



int main() {
	cin >> n;
	memset(dp , -1 , sizeof(dp));

	cout << rec(0, n) << endl ;
}