#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


//ALGORITHM AT 8:00 onwards
//https://www.youtube.com/watch?v=-tgVpUgsQ5k&list=PLgUwDviBIf0oE3gA41TKO2H5bHpPd7fzn&index=5

vector<int> bfs(int V , vector<int> adj[]) {
	int vis[V] = {0};
	vis[0] = 1 ; // bfs starting node is  0

	queue<int> q;
	q.push(0); // starting node is 0 here

	vector <int> bfs;

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		bfs.push_back(node);

		for (auto it : adj[node]) {
			// all neighbours if not visited
			if (!vis[it]) {
				vis[it] = 1 ;
				q.push(it);

			}
		}

	}

	return bfs;

}