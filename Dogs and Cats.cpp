#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    vector <vector <long long> > dp(n + 1, vector <long long>(2));
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % (long long)(1e9+7);
        if (i <= k + 1) dp[i][1] = 1;
        else dp[i][1] = dp[i - k][0];
    }
    cout << (dp[n][0] + dp[n][1]) % (long long)(1e9+7) << "\n";
}
