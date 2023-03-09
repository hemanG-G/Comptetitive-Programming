#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


void dfs(int node , vector<int> adj[] , vector <int> &ls , int vis[]) {
	vis[node] = 1 ;
	ls.push_back(node);

	for (auto it : adj[node]) {
		if (!vis[it]) {
			dfs(it ,  adj , ls , vis);
		}
	}
}



vector <int> dfsofgraph(int  V , vector<int> adj[]) {
	int vis[V] = {0};
	int start  = 0 ;
	vector <int> ls;
	dfs (start , adj , ls , vis);
	return ls;

}