#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, vector <pair <int, int> > > &graph, int cur_node, vector <bool> &vis, vector <int> &dist, unordered_map <int, int> &parents)
{
    vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x.first])
        {
            dist[x.first] = dist[cur_node] + x.second;
            parents[x.first] = cur_node;
            dfs(graph, x.first, vis, dist, parents);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, c;
    cin >> n;
    unordered_map <int, vector <pair <int, int> > > graph;
    for (int x = 1; x < n; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector <bool> vis(n + 1, false), visited(n + 1, false);
    vector <int> dist(n + 1), distance(n + 1);
    unordered_map <int, int> p1, parents;
    dfs(graph, 1, vis, dist, p1);
    int node, node1, maxa = -1, s1 = -1, s2 = INT_MAX;
    for (int x = 1; x <= n; x++)
    {
        if (dist[x] > maxa)
        {
            maxa = dist[x];
            node = x;
        }
    }
    parents[node] = -1;
    dfs(graph, node, visited, distance, parents);
    for (int x = 1; x <= n; x++)
    {
        if (distance[x] > s1)
        {
            s1 = distance[x];
            node1 = x;
        }
    }
    cout << s1 << "\n";
    while (node1 != -1)
    {
        s2 = min(max(s1 - distance[node1], distance[node1]), s2);
        node1 = parents[node1];
    }
    cout << s2 << "\n";
}
