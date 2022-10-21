#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector <int> &vis, vector <int> &dist, unordered_map <int, vector <int> > &graph)
{
    vis[u] = 1;
    for (auto x : graph[u])
    {
        if (vis[x] == 0)
        {
            dist[x] = dist[u] + 1;
            dfs(x, vis, dist, graph);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    unordered_map <int, vector <int> > graph;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
    }
    cin >> a >> b;
    while (a != 0 || b != 0)
    {
        vector <int> vis(10005, 0), dist(10005, -1);
        dist[a] = -1;
        // start from the second node
        int second_node = graph[a].front();
        dist[second_node] = 0;
        dfs(second_node, vis, dist, graph);
        if (vis[b]) cout << "Yes " << dist[b] << endl;
        else cout << "No\n";
        cin >> a >> b;
    }
}
