#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, vector <pair <int, int> > > &graph, int cur_node, vector <bool> &vis, vector <int> &dist, int &max_dist)
{
    vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x.first])
        {
            dist[x.first] = dist[cur_node] + x.second;
            max_dist = max(max_dist, dist[x.first]);
            dfs(graph, x.first, vis, dist, max_dist);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, c, s = 0;
    cin >> n;
    unordered_map <int, vector <pair <int, int> > > graph;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        s += c;
    }
    vector <bool> vis(n + 1);
    vector <int> dist(n + 1);
    int max_dist = -1;
    dfs(graph, 0, vis, dist, max_dist);
    cout << 2 * s - max_dist << "\n";
}
