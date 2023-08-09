// ANAND OZA
#include <vector>

// If there is a cycle, the returned array will not contain all vertices.
std::vector<int> topological_sort(const std::vector<std::vector<int>> &adj) {
	const int n = int(adj.size());
	std::vector<int> deg(n);
	std::vector<int> ans;

	for (int i = 0; i < n; i++) {
		for (int j : adj[i])
			deg[j]++;
	}

	for (int i = 0; i < n; i++) {
		if (deg[i] == 0)
			ans.push_back(i);
	}

	int q = 0;
	while (q < int(ans.size())) {
		int cur = ans[q++];
		for (int next : adj[cur]) {
			if (--deg[next] == 0)
				ans.push_back(next);
		}
	}

	return ans;
}





// ASHISH GUPTA
vector<int> order; //Stores the Topological Order

bool toposort(int n) //Returns 1 if there exists a toposort, 0 if there is a cycle
{
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for (int i = 1; i <= n; i++)
		for (auto &it : g[i])
			indeg[it]++;
	for (int i = 1; i <= n; i++)
	{
		if (!indeg[i])
			q.push(i);
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push_back(u);
		for (auto &v : g[u])
		{
			indeg[v]--;
			if (!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}

//Problem 1: https://www.spoj.com/problems/TOPOSORT/
//Solution 1: http://p.ip.fi/RTRG



// OWN
// gfg topological sort
//{ Driver Code Starts
class Solution
{
public:
	//Function to return list containing vertices in Topological order.
	vector<int> topoSort(int V, vector<int> adj[])
	{
		// code here
		vector<int> indeg(V, 0);
		for (int i = 0 ; i < V  ; i ++) {
			for (auto it : adj[i] ) {
				indeg[it]++;
			}

		}
		queue<int> q;
		vector<int> order;
		for (int i = 0 ; i < V ; i++) {
			if (indeg[i] == 0) {
				q.push(i);
				order.push_back(i);
			}
		}
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (auto i : adj[v]) {
				indeg[i]--;
				if (indeg[i] == 0) {
					q.push(i);
					order.push_back(i);
				}
			}
		}
		return order;
	}
};


