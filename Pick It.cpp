#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    while (n != 0)
    {
        vector <int> vec1(n + 1);
        vector <vector <int> > dp(n + 1, vector <int>(n + 1));
        for (int i = 1; i <= n; i++) cin >> vec1[i];
        for (int k = 2; k <= n - 1; k++)
        {
            for (int i = 1; i <= n - k; i++)
            {
                int j = i + k;
                if (j == i + 2) dp[i][j] = vec1[i] + vec1[i + 1] + vec1[i + 2];
                else
                {
                    dp[i][j] = max(dp[i + 1][j] + vec1[i] + vec1[i + 1] + vec1[j], dp[i][j - 1] + vec1[i] + vec1[j - 1] + vec1[j]);
                    for (int m = i + 2; m <= j - 2; m++) dp[i][j] = max(dp[i][m] + dp[m][j] + vec1[i] + vec1[m] + vec1[j], dp[i][j]);
                }
            }
        }
        cout << dp[1][n] << "\n";
        cin >> n;
    }
}
