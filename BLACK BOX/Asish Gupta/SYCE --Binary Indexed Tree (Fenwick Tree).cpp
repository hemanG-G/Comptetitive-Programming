// VERIFIED 

// BIT
// construct : o(n)
// query & update : o(log N )
// mostly stores prefix sums
// uses bitwise operations to efficiently traverse the tree
// for arry of size n , BIT is of size  n

// each index of BIT represents sum from ( l to r )
// where l = (index with rightmost set bit turned off)
// r = index itself









// 1 base indexing

struct BIT
{
	int N;
	vector<int> bit;

	void init(int n)
	{
		N = n;
		bit.assign(n + 1, 0);
	}

	void update(int idx, int val) 
	{
		while(idx <= N) // logN ( at max log N bits) 
		{
			bit[idx] += val;
			// update all the indexes that contain idx too - > using bitwise magic
			// ( equivalent to 1) 2s compliment of idx -> 2) and with original idx -> 3 ) add to original number = thats the new idx to be updated )
			idx += (idx & -idx);// == idx |= idx +1
		}
	}

	int pref(int idx) // sum upto idx
	{
		int ans = 0;
		while(idx > 0)
		{
			ans += bit[idx];
			idx -= (idx & -idx); // == idx &= idx+1 
			// ( equivalent to 1) 2s compliment of idx -> 2) and with original idx -> 3 ) subtract it from  original number = thats the new idx to be added to curr sum)
		} 
		return ans;
	}

	int rsum(int l, int r) // sum l to r
	{
		return pref(r) - pref(l - 1);
	}


	// Binary lifting (every no can be expressed as power of 2)
	// https://www.youtube.com/watch?v=nuUspQ7ORXE      
	// so idx -1 = nidx -> nidx = maximum index such that pref[nidx] < val
	int search(int val)
	//AUTHOR STATEMENT :returns first index such that pref[idx] >= val
	{
		int curSum = 0, pos = 0;
		for(int i = log2(N) + 1; i >= 0; i--) 
		{
			if(pos + (1 << i) < N && curSum + bit[pos + (1 << i)] < val)
			{
				curSum += bit[pos + (1 << i)];
				pos += (1 << i);
			}
		}
		return pos + 1;
	}


	
	void updateMax(int idx, int val)
	{
		while(idx <= N)
		{
			bit[idx] = max(bit[idx], val);
			idx += idx & -idx;
		}
	}

	int prefMax(int idx)
	{
		int ans = -2e9;
		while(idx > 0)
		{
			ans = max(ans, bit[idx]);
			idx -= idx & -idx;
		}
		return ans;
	}
};

//Problem 1: https://codeforces.com/contest/1073/problem/D
//Solution 1: https://codeforces.com/contest/1073/submission/44863255

//Problem 2: https://www.hackerrank.com/contests/university-codesprint-4/challenges/unique-art/problem
//Solution 2: http://p.ip.fi/T9YM

//Problem 3: https://csacademy.com/contest/round-47/task/cut-the-trees/statement/
