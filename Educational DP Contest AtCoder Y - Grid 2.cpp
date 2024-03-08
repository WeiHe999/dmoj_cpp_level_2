#include <bits/stdc++.h>
using namespace std;


#define int long long

const int MAXN = 2e5;
const int MOD = 1e9 + 7;

int n, m, k, a, b;
map<pair<int, int>, int> dp;

long long fac[MAXN + 1];
long long inv[MAXN + 1];


//  Computes x^n modulo m
long long exp(long long x, long long n, long long m) {
    if (n==0) return 1;
    long long r1 = exp(x, n/2, m);
    r1 = r1 * r1 % m;
    if (n%2==1) r1 = x * r1 % m;
    return r1;
}



/** Precomputes n! from 0 to MAXN. */
void factorial(long long p) {
	fac[0] = 1;
	for (int i = 1; i <= MAXN; i++) { fac[i] = fac[i - 1] * i % p; }
}

/**
 * https://usaco.guide/gold/modular?lang=cpp
 * Precomputes all modular inverse factorials
 * from 0 to MAXN in O(n + log p) time
 */
void inverses(long long p) {
	inv[MAXN] = exp(fac[MAXN], p - 2, p);
	for (int i = MAXN; i >= 1; i--) { inv[i - 1] = inv[i] * i % p; }
}


/** Computes nCr mod p */
long long choose(long long n, long long r, long long p) {
	return fac[n] * inv[r] % p * inv[n - r] % p;
}


int get_num_paths(int x1, int y1, int x2, int y2, int p)
{
    int t = abs(x1-x2) + abs(y1-y2);
    int c = min(abs(x1-x2), abs(y1-y2));
    if (c==0) return 1;
    return choose(t, c, MOD);
}


int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    
    // init
    factorial(MOD);
    inverses(MOD);
    
    cin >> n >> m >> k;
    for (int i = 0; i<k; i++)
    {
        cin >> a >> b;
        dp[{a, b}] = 0;
    }
    dp[{n, m}] = 0;
    

    for (auto x: dp)
    {
        int x1 = x.first.first;
        int y1 = x.first.second;
        dp[{x1, y1}] = get_num_paths(1, 1, x1, y1, MOD);
        for (auto y: dp)
        {
            int x2 = y.first.first;
            int y2 = y.first.second;
            if (x1==x2 && y1==y2) continue;
            if (x2<=x1 && y2<=y1)
            {
               dp[{x1, y1}] = (dp[{x1, y1}] -  (dp[{x2, y2}] * get_num_paths(x2, y2, x1, y1, MOD) % MOD) + MOD) % MOD;
            }
            
        }
    }
   
    cout << dp[{n, m}] << endl;
    
    
    
}
