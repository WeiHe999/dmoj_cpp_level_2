#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    string str1, str2;
    cin >> n >> m >> str1 >> str2;
    vector <vector <int> > memo(n + 1, vector <int>(m + 1));
    for (int i = 1; i <= min(3, n); i++) memo[i][0] = 1;
    for (int i = 1; i <= min(3, m); i++) memo[0][i] = 1;
    for (int i = 4; i <= n; i++) memo[i][0] = memo[i - 3][0] + 1;
    for (int i = 4; i <= m; i++) memo[0][i] = memo[0][i - 3] + 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                memo[i][j] = memo[i - 1][j - 1];
                continue;
            }
            memo[i][j] = min({memo[i - 1][j] + 1, memo[i][j - 1] + 1, memo[i - 1][j - 1] + 1});
            if (i > 1) memo[i][j] = min(memo[i - 2][j] + 1, memo[i][j]);
            if (j > 1) memo[i][j] = min(memo[i][j - 2] + 1, memo[i][j]);
            if (i > 2) memo[i][j] = min(memo[i - 3][j] + 1, memo[i][j]);
            if (j > 2) memo[i][j] = min(memo[i][j - 3] + 1, memo[i][j]);
        }
    }
    cout << memo[n][m] << "\n";
}
