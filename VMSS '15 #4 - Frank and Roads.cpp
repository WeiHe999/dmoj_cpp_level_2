#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, vector <pair <int, int> > > &graph, vector <int> &dist, vector <bool> &vis)
{
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q1;
    q1.push({0, start_node});
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.top();
        q1.pop();
        if (vis[cur_node.second]) continue;
        vis[cur_node.second] = true;
        for (auto x : graph[cur_node.second])
        {
            if (cur_node.first + x.second < dist[x.first])
            {
                dist[x.first] = cur_node.first + x.second;
                q1.push({dist[x.first], x.first});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, n, m, g, a, b, c, s = 0;
    cin >> t >> n >> m >> g;
    vector <int> dest(g);
    unordered_map <int, vector <pair <int, int> > > graph;
    for (int x = 0; x < g; x++) cin >> dest[x];
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    vector <int> dist(n + 1, INT_MAX);
    vector <bool> vis(n + 1, false);
    dijkstra(0, graph, dist, vis);
    for (auto x : dest) if (dist[x] <= t) s++;
    cout << s << "\n";
}
