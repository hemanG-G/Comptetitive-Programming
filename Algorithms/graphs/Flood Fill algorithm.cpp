#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


// flood fill algorithm   with DFS


void dfs(int row , int col, vector<vector<int>>& image , vector<vector<int> > &ans , int iniColor , int delrow[] , int delcol[] , int newColor ) {
	ans[row][col] = newColor;
	for (int i = 0 ; i < 4 ; i ++) {

		int n = image.size();
		int m = image[0].size();

		int nrow = row + delrow[i];
		int ncol = col + delcol[i];
		if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
		        && image[nrow][col] == iniColor &&  ans[nrow][ncol] != newColor) {
			dfs(nrow, ncol , image , ans , iniColor , delrow , delcol , newColor );
		}

	}

}



vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int iniColor = image[sr][sc];
	vector<vector<int> > ans = image; // duplicate

	int delrow[] = { -1, 1, 0, 0};
	int delcol[] = {0, 0, -1, 1};


	// calling dfs on ans from (sr,sc)
	dfs(sr , sc , image, ans , iniColor , delrow , delcol, newColor);

	return ans;
}