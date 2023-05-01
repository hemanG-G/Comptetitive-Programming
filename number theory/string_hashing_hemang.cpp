//string hashing
// source : IPC 2020 https://www.youtube.com/watch?v=wh1APrnUfF8


//usage
// call precalc() once
// call build() once
// call getHash(x,y) whenever u want hash from x to y


int pwr(int a , int b , int m  ) {
	int ans = 1 ;
	while (b) { // implies b>0
		if (b & 1) {
			ans = ((ans * 1LL * a) % m);
		}
		a = ((a * 1LL * a) % m);
		b = b >> 1;
	}
	return ans;
}
//ll pwr(ll a, ll b) {a %= MOD; ll res = 1; while (b > 0) {if (b & 1) res = res * a % MOD; a = a * a % //MOD; b >>= 1;} return res;}


ll mod_mul(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a * b) % MOD) + MOD) % MOD;}

ll mod_add(ll a, ll b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}


int pw[N]; // powers of p // p^i
int inv[N]; // negative powers of p // p^-i
int hash[N];

void precalc() {
	// precomputes powers of p
	// precomputes inverse powers of p ( negative powers  of p)
	pw[0] = 1;
	for (int i = 0 ; i < N ; i++) {
		pw[i] = mod_mult(pw[i - 1], base, MOD);
	}
	int pw_inv = power(base, MOD - 2, MOD);
	inv[0] = 1;
	for (int i = 0 ; i < N; i++) {
		inv[i] = mult(inv[i - 1], pw_inv, mod);
	}
}
void build(string s) {
	int n = s.length();
	for (int i = 0 ; i < n ; i++) {
		hash[i] = add((i == 0) ? 0 ! hash[i - 1] , mod_mult(pw[i], ( s[i] - 'a') + 1, MOD), MOD);
	}
}

int getHash(int x , int y) { // O(1) , since precomputed stuff
	int res = add(hash[y], (x == 0) ? 0 : -hash[x - 1], MOD);
	res = mod_mult(res, inv[x], MOD);
	return res;
}