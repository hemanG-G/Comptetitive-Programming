// /// How many numbers x are there in the range a to b, where the digit d occurs exactly k times in x?

#include <bits/stdc++.h>
using namespace std;

vector<int> num;
int a, b, d, k;
int DP[12][12][2];
/// DP[p][c][f] = Number of valid numbers <= b from this state
/// p = current position from left side (zero based)
/// c = number of times we have placed the digit d so far
/// f = the number we are building has already become smaller than b? [0 = no, 1 = yes]

int call(int pos, int cnt, int f){
    if(cnt > k) return 0;

    if(pos == num.size()){
        if(cnt == k) return 1;
        return 0;
    }

    if(DP[pos][cnt][f] != -1) return DP[pos][cnt][f];
    int res = 0;

    int LMT;

    if(f == 0){
        /// Digits we placed so far matches with the prefix of b
        /// So if we place any digit > num[pos] in the current position, then the number will become greater than b
        LMT = num[pos];
    } else {
        /// The number has already become smaller than b. We can place any digit now.
        LMT = 9;
    }

    /// Try to place all the valid digits such that the number doesn't exceed b
    for(int dgt = 0; dgt<=LMT; dgt++){
        int nf = f;
        int ncnt = cnt;
        if(f == 0 && dgt < LMT) nf = 1; /// The number is getting smaller at this position
        if(dgt == d) ncnt++;
        if(ncnt <= k) res += call(pos+1, ncnt, nf);
    }

    return DP[pos][cnt][f] = res;
}

int solve(int b){
    num.clear();
    while(b>0){
        num.push_back(b%10);
        b/=10;
    }
    reverse(num.begin(), num.end());
    /// Stored all the digits of b in num for simplicity

    memset(DP, -1, sizeof(DP));
    int res = call(0, 0, 0);
    return res;
}

int main () {

    cin >> a >> b >> d >> k;
    int res = solve(b) - solve(a-1);
    cout << res << endl;

    return 0;
}



///////////////////////////////////

// ASISH GUPTA

//For Decimals

int sz = 0;
int x[20];
int cache[20][2][5];

int dp(int idx, bool less, int taken)
{
	if(taken > 3)
		return 0;
	if(idx == sz)
		return 1;
	int &ans = cache[idx][less][taken];
	if(ans != -1)
		return ans;
	ans = 0;
	int lo = 0, hi = 9;
	if(!less)
		hi = x[idx];
	for(int i = lo; i <= hi; i++)
		ans += dp(idx + 1, less | (i < x[idx]), taken + (i > 0));
	return ans;
}

int f(int k)
{
	memset(cache, -1, sizeof(cache));
	sz = 0;
	while(k > 0)
	{
		x[sz++] = k % 10;
		k /= 10;
	}
	reverse(x, x + sz);
	int ans = dp(0, 0, 0);
	return ans;
}

//Example of using with both L and R: https://github.com/nachiketkanore/CP-Snippets/blob/master/Digit_DP_%5BL%2CR%5D_some_property.cpp

//Problem 1: https://codeforces.com/contest/1036/problem/C

//Problem 2: https://codeforces.com/contest/628/problem/D

