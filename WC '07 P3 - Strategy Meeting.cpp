#include <bits/stdc++.h>
using namespace std;

long long rec(long long bitmask, long long cur, vector <vector <long long> > grid, vector <vector <long long> > &dp)
{
    if (cur == grid.size() - 1) return dp[bitmask][cur] = 1;
    if (dp[bitmask][cur] != -1) return dp[bitmask][cur];
    long long s = 0;
    for (long long i = 0; i < grid.size(); i++)
    {
        if ((bitmask & (1 << i)) || (!grid[cur][i])) continue;
        s = (s + rec(bitmask | (1 << i), i, grid, dp)) % 13371337;
    }
    return dp[bitmask][cur] = s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t;
    cin >> t;
    for (long long x = 1; x <= t; x++)
    {
        long long n;
        cin >> n;
        vector <vector <long long> > grid(n, vector <long long>(n));
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> grid[i][j];
        vector <vector <long long> > dp(1 << n, vector <long long>(n, -1));
        cout << rec(1, 0, grid, dp) % 13371337 << "\n";
    }
}
