#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, vector <pair <int, int> > > &graph, vector <int> &dist)
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
    int n, m, a, b, c, d;
    cin >> n >> m;
    unordered_map <int, vector <pair <int, int> > > graph, graph2;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph2[b].push_back({a, c});
    }
    vector <int> dist(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
    dist[1] = 0;
    dist2[n] = 0;
    dijkstra(1, graph, dist);
    dijkstra(n, graph2, dist2);
    int s = dist[n];
    cin >> d;
    for (int x = 0; x < d; x++)
    {
        cin >> a >> b >> c;
        if (dist[a] != INT_MAX && dist2[b] != INT_MAX) s = min(dist[a] + c + dist2[b], s);
    }
    if (s != INT_MAX) cout << s << "\n";
    else cout << "-1\n";
}
