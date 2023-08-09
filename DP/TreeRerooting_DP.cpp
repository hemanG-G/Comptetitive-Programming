// tree rooting
// solution to : https://cses.fi/problemset/result/6345926/



vi res, nodecnt;
void dfs1(int node, int p , vvi adj ) {
	nodecnt[node] = 1;
	for (auto x : adj[node] ) {
		if (x == p)continue;
		dfs1(x, node, adj);
		//after done calc for children
		res[node] += res[x] + nodecnt[x]; // res = sum of all dist from node,
		nodecnt[node] += nodecnt[x];
		// inintially res for all is calc
	}
}
void dfs2(int node, int p , vvi adj ) {
	// int n
	int n = adj.size() - 1 ; // its n+1
	// jus after enter new node
	if (p != -1) {
		res[node]  = res[p] - nodecnt[node] + (n - nodecnt[node]) ;
	}


	for (auto ch : adj[node]) {
		if (ch == p)continue;
		dfs2(ch, node, adj);

	}

}
void solve(int tc) {
	int n = 1;
	cin >> n ;
	// adj.assign(n + 1, 0);
	vvi adj(n + 1);
	res.assign(n + 1, 0);
	nodecnt.assign(n + 1, 0);
	fo(i, 1, n - 1) {
		int a, b; cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs1(1, -1, adj); // getting the node cnt & res[1]

	dfs2(1, -1, adj);

	fo(i, 1, n ) {
		cout << res[i] << ' ';
	}

	cout << '\n';
}
