#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

// QN
// given x1 ,x2 ,... xn , find LIS(longest increasing subsequence)


// using FORM 2 ,
//--return required from start to INDEX  APPROACH

int n ;
int xi[100];
int dp[10001];


int rec(int level) {
	// returns what= LIS ,from 1 to level , ****ENDING AT LEVEL****

	//pruning
	if (level < 0 || level >= n ) {
		return 0;
	}
	//basecase == not required ,covered in pruning


	//cache check
	if ( dp[level] != -1) {
		return dp[level];
	}



	//transitions / compute

	int ans = 1; // default ans is 1 sized subsequence

	// if i extend previous LIS , by taking current level
	// check
	for ( int prev = 0 ; prev < level ; prev++) {
		if (xi[prev] < xi[level] ) {
			//taking it
			// ans is max of previous LIS from 1 to level , extended by 1
			ans = max(ans , rec(prev) + 1);


			//above is equivalent to , by iteratino of recursion
			// ans = max of all prev LIS's +1)
		}
	}



	//save and return
	dp[level] = ans;
	return ans;

}


int main() {
	cin >> n;
	for (int i = 0 ; i < n ; i ++) {
		cin >> xi[i];
	}


	memset(dp, -1, sizeof(dp));


	// recursion call
	// rec(n)== max LIS from 1 to n , ENDING AT N , so wrong ,
	// we dont want ending at n , we want throught all


	//correct call
	int anss = 1;
	for (int i = 0 ; i < n ; i++ ) {
		anss = max(anss, rec(i));
	}
	cout << anss << endl;
}