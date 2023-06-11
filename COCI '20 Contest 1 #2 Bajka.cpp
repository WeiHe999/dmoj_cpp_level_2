#include <bits/stdc++.h>
using namespace std;

int n, m, s = 1e9;
vector <vector <int> > dp(301, vector <int>(301, -1));
string str1, str2;

int rec(int i, int j)
{
    if (j == m) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int ans = 1e9;
    for (int a = 0; a < n; a++)
    {
        if (str1[a] == str1[i])
        {
            for (int b = -1; b < 2; b++)
            {
                if (!b || a + b < 0 || a + b >= n) continue;
                if (str1[a + b] != str2[j]) continue;
                ans = min(rec(a + b, j + 1) + abs(a - i) + 1, ans);
            }
        }
    }
    return dp[i][j] = ans;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> str1 >> str2;
    for (int i = 0; i < n; i++) if (str1[i] == str2[0]) s = min(rec(i, 1), s);
    if (s >= 1e9) cout << "-1\n";
    else cout << s << "\n";
}
