#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, unordered_set <int> > &graph, int cur_node, vector <bool> &vis, vector <int> &dist)
{
    vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x])
        {
            dist[x] = dist[cur_node] + 1;
            dfs(graph, x, vis, dist);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    unordered_map <int, unordered_set <int> > graph;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector <bool> vis(n + 1), visited(n + 1), visited2(n + 1);
    vector <int> d(n + 1), dist1(n + 1), dist2(n + 1);
    dfs(graph, 1, vis, d);
    int max_dist = -1, max_node;
    for (int x = 1; x < d.size(); x++)
    {
        if (d[x] > max_dist)
        {
            max_dist = d[x];
            max_node = x;
        }
    }
    dfs(graph, max_node, visited, dist1);
    max_dist = -1;
    for (int x = 1; x < dist1.size(); x++)
    {
        if (dist1[x] > max_dist)
        {
            max_dist = dist1[x];
            max_node = x;
        }
    }
    dfs(graph, max_node, visited2, dist2);
    for (int i = 1; i <= n; i++) cout << max(dist1[i], dist2[i]) + 1 << "\n";
}
