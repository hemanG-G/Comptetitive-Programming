EXPLAIN THIS CODE'S LOGIC TO ME IN ABSTRACT SHORT ALOGIRHTM WHAT ARE DOING


void solve(int tc) {
    // !!!!!!!! EK TU HI NIRANKAR!!!!!!!!!!!!!
    int n,m;
    cin>>n>>m;
 
    int a[n];
    for(int i=0;i<n;i++){cin>>a[i];}
 
    sort(a,a+n);
 
    int pref[n];
    pref[0]=a[0];
    for(int i=1;i<n;i++){pref[i]=pref[i-1]+a[i];}
 
    int ans=0;
    for(int i=0;i<n;i++)
    {
 
        if(a[i]>m){continue;}
        int x=0;
        if(i>0){x=pref[i-1];}
        int ok=x;
        x=x+m;
        int p=lower_bound(pref,pref+n,x+1)-pref;
        p--;
        int q=lower_bound(a,a+n,a[i]+2)-a;
        q--;
        int c=min(p,q);
        ans=max(ans,pref[c]-ok);
    }
    
    cout << ans << nl;
