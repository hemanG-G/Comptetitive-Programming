//example :
// https://atcoder.jp/contests/abc361/tasks/abc361_e



 void solve(int tc) {
    // not MST cuz we want not just the skeleton
    // we wan start to end , so multople double paths
    // so ans is : 2* all - (start to end dist)
    // so maximize start to end dist = diameter of tree , thats the problem
    ll n;
    cin>>n;
    vector<vpii> e(n);
    ll len = 0;
    for(ll i=0;i<n-1;i++){
        ll u,v,c;
        cin>>u>>v>>c;
        u--;v--;
        e[u].pb(pii{v,c});
        e[v].pb(pii{u,c});
        len+=c;
    }


    // DFS :getting diameter of tree
    // algo : pick any point -> go farthest dist to point b -> from point b again go farthest dist to point a 
    // a-b is the diameter
    
    
    // dfs implementation below
    // retursn {max farthest distance , node }
    auto run=y_combinator([&](const auto &self,const ll u,const ll p)->pii{
        pii cur = pii{0,u}; // start form any current node { zero dist , node}
        for(const auto &x:e[u]){
            if(x.ff==p)
                continue;
            auto child=self(x.ff,u); // 1. get the farthest node of child -> cld ={child node ka farthest dist , child node}
            child.ff+=x.ss;          // 2. add current dist to update child  -> cld ={curr edge dist + child node ka farthest dist  , child node}
            cur=max(cur,child);      // 3. keep max value of dist in cur -> return it
        }
        return cur;
    });
    
    int diameter= run(run(0,-1).ss,-1).ff ;
    
    cout<<2*len-diameter<<endl;

}
    
    