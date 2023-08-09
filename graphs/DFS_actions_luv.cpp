#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;


vector <int> graph[N];
bool vis[N]; // visited array

bool dfs(int vertex) {
	//****take action on vertex node , AFTER entering verteX********
	vis[vertex] = true;

	for (auto child : graph[vertex] ) {
		//******Take action on child , BEFORE entering child node******
		if (vis[child]) continue;

		dfs(child);
		//****take action AFTER  exiting child node*****
	}

	//****take action on vertex node , BEFORE exiting vertex node****
}


int main() {
	int n , m ;
	cin >> n >> m ;

	for ( int i = 0 ; i < m  ; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

}