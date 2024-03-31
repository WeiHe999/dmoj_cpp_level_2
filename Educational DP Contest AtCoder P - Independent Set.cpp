#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

int n, a, b;
unordered_map <int, vector <int> > graph;
vector <vector <int> > dp;

void dfs(int cur, int prev)
{
    if (graph[cur].size() == 1 && prev != -1)
    {
        dp[cur][0] = 1, dp[cur][1] = 1;
        return;
    }
    int s1 = 1, s2 = 1;
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs(x, cur);
        s1 = (s1 * (dp[x][0] + dp[x][1])) % mod, s2 = (s2 * dp[x][0]) % mod;
    }
    dp[cur][0] = s1, dp[cur][1] = s2;
}


int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    dp.resize(n + 1, vector <int>(2, -1));
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(1, -1);
    cout << (dp[1][0] + dp[1][1]) % mod << "\n";
}
