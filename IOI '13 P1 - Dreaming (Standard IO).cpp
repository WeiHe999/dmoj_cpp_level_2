#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+3;

int n, m, l, a, b, t, max_dist, max_val, dia1, dia2, cur, radius;
vector <vector <pair <int, int> > > adj(MM);
vector <int> dist(MM), parents(MM), tmp(MM), radii, dias;
vector <bool> vis(MM, false);

void dfs(int cur, int prev)
{
    vis[cur] = true;
    for (auto x : adj[cur])
    {
        if (x.first == prev) continue;
        dist[x.first] = dist[cur] + x.second;
        parents[x.first] = cur;
        if (dist[x.first] > max_dist)
        {
            max_dist = dist[x.first];
            max_val = x.first;
        }
        dfs(x.first, cur);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> t;
        adj[a].emplace_back(b, t);
        adj[b].emplace_back(a, t);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i]) continue;
        if (adj[i].empty())
        {
            radii.emplace_back(0);
            dias.emplace_back(0);
            continue;
        }
        max_dist = -1;
        dist[i] = 0;
        dfs(i, -1);
        dia1 = max_val;
        parents[dia1] = -1;
        max_dist = -1;
        dist[dia1] = 0;
        dfs(dia1, -1);
        dia2 = max_val;
        dias.emplace_back(max_dist);
        cur = dia2;
        radius = 1e9;
        do
        {
            radius = min(max(dist[cur], dist[dia2] - dist[cur]), radius);
            cur = parents[cur];
        } while (cur != -1);
        radii.emplace_back(radius);
    }
    sort(radii.rbegin(), radii.rend());
    sort(dias.rbegin(), dias.rend());
    if (radii.size() == 1) cout << dias[0] << "\n";
    else
    {
        if (radii.size() == 2) cout << max(radii[0] + l + radii[1], dias[0]) << "\n";
        else cout << max({radii[0] + l + radii[1], dias[0], radii[1] + 2 * l + radii[2]});
    }
}
