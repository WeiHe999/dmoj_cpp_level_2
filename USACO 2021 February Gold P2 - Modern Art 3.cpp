#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    vector <vector <int> > dp(n + 1, vector <int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = n; i >= 1; i--)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (vec1[i] == vec1[j]) dp[i][j] = max(dp[i][j], 1 + dp[i + 1][j - 1]);
            for (int m = i + 1; m <= j - 1; m++) dp[i][j] = max(dp[i][m] + dp[m][j], dp[i][j]);
        }
    }
    cout << n - dp[1][n] << "\n";
}
