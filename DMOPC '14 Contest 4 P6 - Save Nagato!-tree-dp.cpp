#include <bits/stdc++.h>
using namespace std;
const int MM = 5e5 + 5;

int n, a, b;
unordered_map <int, vector <int> > graph;
vector <int> dist1(MM), dist2(MM), ans(MM);

void dfs1(int cur, int prev)
{
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs1(x, cur);
        if (dist1[x] + 1 > dist1[cur])
        {
            dist2[cur] = dist1[cur];
            dist1[cur] = dist1[x] + 1;
        }
        else if (dist1[x] + 1 > dist2[cur]) dist2[cur] = dist1[x] + 1;
    }
}

void dfs2(int cur, int prev, int d_outside)
{
    ans[cur] = max(d_outside, dist1[cur]);
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        if (dist1[x] + 1 == dist1[cur]) dfs2(x, cur, max(d_outside + 1, dist2[cur] + 1));
        else dfs2(x, cur, max(d_outside + 1, dist1[cur] + 1));
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs1(1, -1);
    dfs2(1, -1, 0);
    for (int i = 1; i <= n; i++) cout << ans[i] + 1 << "\n";
}
