for this problem , we are essentially taking max of first type and then taking whatever
is left of the next i+1 type , then we realise its better to take i+1 type as our goal
is to spend as much petals as possible , so we sell first type and get the second type , this costs us 1 petal for each trasfer
is my understanding till now correct?

so my question is cant we just reverse the order of iteration , so that we dont need to make the transfers
we can just take as max as we can for i and then with the remaining we can take i-1 , theres no need for transfers
if this is correct give me c++ code


cin >> n >> m;
        for (int i = 0; i < n; i++) cin >> p[i].first;
        for (int i = 0; i < n; i++) cin >> p[i].second;
 
        sort(p, p + n);
 
        int ans = 0;
 
        for (int i = 0; i < n; i++) {
            int val = min(m / p[i].first, p[i].second);
            ans = max(ans, val * p[i].first);
        }
 
        for (int i = 0; i < n - 1; i++) {
            if (p[i].first + 1 != p[i + 1].first) continue;
 
            int cur = m;
 
            int a = min(cur / p[i].first, p[i].second);
            cur -= a * p[i].first;
 
            int b = min(cur / p[i + 1].first, p[i + 1].second);
            cur -= b * p[i + 1].first;
 
            int x = min({a, p[i + 1].second - b, cur});
            cur -= x;
 
            ans = max(ans, m - cur);
        }
 
        cout << ans << '\n';