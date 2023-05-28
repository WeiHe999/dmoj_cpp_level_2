#include <bits/stdc++.h>
using namespace std;

vector <vector <long long> > dp(20, vector <long long>(1 << 20, -1)), grid(20, vector <long long>(20, -1));

long long rec(long long cur, long long bitmask, long long n)
{
    if (dp[cur][bitmask] != -1) return dp[cur][bitmask];
    long long s = 0, x;
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if ((grid[cur][i] != -1) && (i != cur) && (bitmask & (1 << i)))
        {
            x = rec(i, bitmask & ~(1 << i), n);
            if (x != (-1 * 1e9))
            {
                flag = false;
                x += grid[cur][i];
                s = max(x, s);
            }
        }
    }
    if (flag && (bitmask & (1 << (n - 1)))) return dp[cur][bitmask] = -1 * 1e9;
    return dp[cur][bitmask] = s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, a, b, c;
    cin >> n >> m;
    for (long long j = 0; j < m; j++)
    {
        cin >> a >> b >> c;
        grid[a][b] = c;
    }
    for (long long i = 0; i < (1 << n); i++) dp[n - 1][i] = 0;
    cout << rec(0, (((1 << n) - 1) & ~(1)), n) << "\n";
}
