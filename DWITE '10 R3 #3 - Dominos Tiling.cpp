#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int x = 1; x <= 5; x++)
    {
        int n;
        cin >> n;
        vector <vector <int> > dp(n + 1, vector <int>(8));
        dp[0][7] = 1;
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = dp[i - 1][7];
            dp[i][1] = dp[i - 1][6];
            dp[i][2] = dp[i - 1][5];
            dp[i][3] = (dp[i - 1][4] + dp[i - 1][7]) % 1000000;
            dp[i][4] = dp[i - 1][3];
            dp[i][5] = dp[i - 1][2];
            dp[i][6] = (dp[i - 1][1] + dp[i - 1][7]) % 1000000;
            dp[i][7] = (dp[i - 1][0] + dp[i - 1][3] + dp[i - 1][6]) % 1000000;
        }
        cout << dp[n][7]  << "\n";
    }
}
