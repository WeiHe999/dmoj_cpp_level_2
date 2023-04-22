#include <bits/stdc++.h>
using namespace std;

long long pairs(char a, char b)
{
    string opened = "([{", closed = ")]}";
    long long s = 0;
    for (long long t = 0; t <= 2; t++) if ((a == opened[t] || a == '?') && (b == closed[t] || b == '?')) s++;
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    string str1;
    cin >> n >> str1;
    bool flag = false;
    vector <vector <long long> > dp(n + 1, vector <long long>(n + 1));
    for (long long k = 1; k <= n - 1; k += 2)
    {
        for (long long i = 1; i <= n - k; i++)
        {
            long long j = i + k, s = 0;
            if (j == i + 1)
            {
                dp[i][j] = pairs(str1[i - 1], str1[j - 1]);
                continue;
            }
            for (long long m = i + 1; m <= j; m += 2)
            {
                if (m == i + 1) s = (s + pairs(str1[i - 1], str1[m - 1]) * dp[m + 1][j]);
                else if (m == j) s = (s + pairs(str1[i - 1], str1[m - 1]) * dp[i + 1][m - 1]);
                else s = (s + pairs(str1[i - 1], str1[m - 1]) * dp[i + 1][m - 1] * dp[m + 1][j]);
            }
            if (s >= 100000)
            {
                dp[i][j] = s % 100000;
                if (i == 1 && j == n) flag = true;
            }
            else dp[i][j] = s;
        }
    }
    if (flag) for (int i = 1; i <= 5 - to_string(dp[1][n]).size(); i++) cout << 0;
    cout << dp[1][n] << "\n";
}
