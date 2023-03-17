#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string str1, str2;
    cin >> n >> str1;
    vector <int> vec1(n + 1), vec2(n + 1);
    vector <vector <int> > grid(n + 1, vector <int>(n + 1)), memo(n + 1, vector <int>(n + 1));
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    cin >> str2;
    for (int i = 1; i <= n; i++) cin >> vec2[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((str1[i - 1] != str2[j - 1] && str1[i - 1] == 'L' && vec1[i] < vec2[j])) grid[i][j] = vec1[i] + vec2[j];
            if ((str1[i - 1] != str2[j - 1] && str1[i - 1] == 'W' && vec1[i] > vec2[j])) grid[i][j] = vec1[i] + vec2[j];
        }
    }
    memo[n][n] = grid[n][n];
    for (int i = n; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            if (i == n && j == n) continue;
            else if (i == n) memo[n][j] = max(memo[n][j + 1], grid[n][j]);
            else if (j == n) memo[i][n] = max(memo[i + 1][n], grid[i][n]);
            else memo[i][j] = max({grid[i][j] + memo[i + 1][j + 1], memo[i + 1][j], memo[i][j + 1]});
        }
    }
    cout << memo[0][0] << "\n";
}
