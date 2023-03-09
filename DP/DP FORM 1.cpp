#include <bits/stdc++.h>
using namespace std;


//DP FORM 1
//Q: given N problems , each problem given Si skill gain , and  takes Ti time ,
//   you have X time and K slots , find maximum skill gain you can get , with these constraints
//  given :   T1   T2   T3    T4    T5...         Tn
//			  S1   S2   S3    S4    S5...         Sn





// // FRAME WORK
// 1) idenitfy the form
// - form 1

// 2) decide states & meanings
// rec(level, timetaken , itemtaken) returns whats asked in qn .
// i.e max skill gain from (level...n-1),considering 0...level
// is already set with parameters itemtaken & timetaken

// 3) decide transitions
// 2 transitions here== take or not itemtaken



// 4) decide timecomplexity
// -using formula == (no of states)*( 1 + no of transitions)
//                == ( N * x *k ) * ( 1+ 2)

// 5)code
//   1-pruning
//   2-basecase
// ****  3- CACHE CHECK // CHECK IF IT EXISTS IN DP ARRAY
//   4-transitions
//  ****  5-save&return // CACHE THE ANS TO DP ARRAY , AND RETURN IT





// CODE
int n;
int x , k ;
int dp[101][101][101];
int ti[1001];
int si[1001];


int rec(int level, int timetaken , int itemtaken) {

	// 1 pruning

	// 2  basecase
	if (level == n ) {
		return 0 ; // min/max problem == valid base == return 0
	}


	// 3  cache check
	if (dp[level][timetaken][itemtaken] != -1) {
		return dp[level][timetaken][itemtaken];
	}

	// 4 TRANSITION
	//2options (take or not take)
	//if i dont take
	int ans = rec( level + 1 , timetaken , itemtaken); // DECLARING ANS HERE NO ISSUE

	//if i take (ONLY IF CHECK PASS)
	if (timetaken + ti[level] <= x && itemtaken + 1 <= k) {
		/****NOW CHOOSING MAX OF BOTH POSSBILE CASES(TRANSITIONS) , MAX(TAKEN, NOT TAKEN)********/
		ans += max(ans , si[level] + rec(level + 1, timetaken + ti[level], itemtaken + 1) );
	}



	// 5 save and return
	ans = dp[level][timetaken][itemtaken]; // storing unique location in array , for all 3 parameters
	return  ans; // whats asked in qn just from level to n-1 , following constrints
}



int main() {
	cin >> n ;

	cin >> x >> k ;
	for (int i = 0 ; i < n ; i ++) {
		cin >> si[i] >> ti[i];
	}

	memset(dp, -1, sizeof(dp)); // INITIALIZING DP ARRAY
	cout << rec(0, x, k) << endl; // zero based indexing ,

}