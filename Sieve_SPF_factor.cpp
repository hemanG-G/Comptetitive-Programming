// spf (smallest prime factor) using seieve
//logic  = for a no the square of it and mulitples after square , have their SPF as this no
// start building from 2 


vll SPF(N+1,1) ; // DONT CALL INSIDE TEST CASE/ CALL ONCE ONLY
void spf() { 
	ll i, j;
	for(i=2; i <=N ; i++){
		if(SPF[i]==1){
			SPF[i]=i;
			for(j = i*i ; j<=N ; j+=i){
				if(SPF[j]==1){
					SPF[j]=i;
				}
			}
		}
	}
	
}

// prime factorize using spf : 
// logic : keep dividing  no by spf , and the resulting no's spf is pushed into prime factor vector
vll factorize(ll n){ // O (logN)
	vll ans ;
	while(n>1){
		ll fact = SPF[n];
		while(n%fact==0){
			n/=fact;
		}
		ans.pb(fact);
	}
	return ans;
}