
#include <bits/stdc++.h>
using namespace std;

int n , m , l;
string a , b , c;
int dp[101][101][101];



//multisequence DP
int rec(int i , int j, int k) { // returns  length of LCS ( longest common substring ) in i...n and j.....m and k ....l

	// pruning


	//basecase
	if (i >= n || j >= m || k >= l) {
		return 0; // counting problem
	}

	//cache check
	if ( dp[i][j][k] != -1) {
		return dp[i][j][k];
	}


	// transitions / compute
	int ans = 0;


	// 3 casess
	// TAKING MAX ACROSS ALL  THREE CASES
	ans = max ( ans , rec(i, j + 1 , k)); // ALWAYS possible case 1
	ans = max ( ans , rec(i + 1, j , k )); // ALWAYSpossible case 2
	ans = max ( ans , rec(i, j, k + 1)); // ALWAYSpossible case 3


	if (a[i] == b[j] == c[k]) { // DONT MISS THE CHECK.
		ans = max ( ans , 1 + rec(i + 1, j + 1 , k + 1)); // ADDING 1 TO LCS **
	}


	// save and return
	ans = dp[i][j][k];
	return  ans;

}

int main() {
	cin >> n >> m >> l;
	cin >> a >> b >> c;

	memset(dp, -1, sizeof(dp));
	cout << rec(0, 0 , 0) << endl;

}