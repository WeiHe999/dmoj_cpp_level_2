#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> cherries;
unordered_map <int, vector <pair <int, int> > > graph;
vector <vector <int> > dp;

void solve(int cur, int prev, int val)
{
    if (graph[cur].size() == 1 && prev!=-1)
    {
        dp[cur][0] = cherries[cur];
        dp[cur][1] = val;
        return;
    }
    if (dp[cur][0] != -1) return;
    dp[cur][0] = cherries[cur], dp[cur][1] = val;
    for (auto x : graph[cur])
    {
        if (x.first == prev) continue;
        solve(x.first, cur, x.second);
        dp[cur][0] += dp[x.first][0];
        dp[cur][1] += dp[x.first][1];
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, c, k, a, b, d, s = 0;
    cin >> n >> c >> k;
    cherries.resize(n + 1);
    dp.resize(n + 1, vector <int>(2, -1));
    for (int i = 1; i <= n; i++) cin >> cherries[i];
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> d;
        graph[a].push_back({b, d});
        graph[b].push_back({a, d});
    }
    solve(1, -1, 0);
    dp[1] = {-1, -1};
    for (auto x : dp) if (x[0] >= c && x[1] <= k) s++;
    cout << s << "\n";
}
