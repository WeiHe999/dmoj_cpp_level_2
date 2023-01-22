#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, unordered_map <int, int> > graph, vector <int> &dist)
{
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q1;
    q1.push({0, start_node});
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.top();
        q1.pop();
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
    int n, m, a, b, c;
    cin >> n >> m;
    unordered_map <int, unordered_map <int, int> > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        if (!graph[a].count(b))
        {
            graph[a][b] = c;
            graph[b][a] = c;
        }
        else
        {
            graph[a][b] = min(graph[a][b], c);
            graph[b][a] = min(graph[a][b], c);
        }
    }
    vector <int> dist(n + 1, INT_MAX);
    dist[1] = 0;
    dijkstra(1, graph, dist);
    for (int x = 1; x <= n; x++)
    {
        if (dist[x] != INT_MAX) cout << dist[x] << "\n";
        else cout << "-1\n";
    }
}
