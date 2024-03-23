#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

vector <int> vec1, psa, tmp;
vector <vector <int> > dp;

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    vec1.resize(n + 1);
    psa.resize(k + 1, 1);
    tmp.resize(k + 1);
    dp.resize(n + 1, vector <int>(k + 1));
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 1; i <= k; i++) dp[0][i] = 0;
    for (int i = 1; i <= n; i++)
    {
        tmp[0] = 1;
        for (int j = 1; j <= k; j++)
        {
            if (j - vec1[i] - 1 < 0) dp[i][j] = psa[j];
            else dp[i][j] = (psa[j] - psa[j - vec1[i] - 1] + mod) % mod;
            tmp[j] = (tmp[j - 1] + dp[i][j]) % mod;
        }
        psa = tmp;
    }
    cout << dp[n][k] << "\n";
}
