#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 2, maxa;
    cin >> n;
    vector <long long> vec1(n + 1), dp(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    dp[0] = 1ll;
    dp[1] = 1ll;
    maxa = vec1[1];
    for (long long i = 2; i <= n; i++)
    {
        if (vec1[i] < maxa) dp[i] = dp[i - 1];
        else dp[i] = s;
        s = (s + dp[i]) % (long long)(1e9+7);
        maxa = max(vec1[i], maxa);
    }
    cout << dp[n] % (long long)(1e9+7) << "\n";
}
