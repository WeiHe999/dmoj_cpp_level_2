#include <bits/stdc++.h>
using namespace std;

int MM = 1e9;

void dijkstra(int start_node, unordered_map <int, vector <pair <int, int> > > &graph, vector <int> &dist, vector <int> &danger)
{
    priority_queue <vector <int>, vector <vector <int> >, greater <vector <int> > > q1;
    q1.push({danger[start_node], dist[start_node], start_node});
    while (!q1.empty())
    {
        vector <int> cur_node = q1.top();
        q1.pop();
        for (auto x : graph[cur_node[2]])
        {
            if (cur_node[0] + x.second < danger[x.first] || (cur_node[0] + x.second == danger[x.first] && cur_node[1] + 1 < dist[x.first]))
            {
                dist[x.first] = cur_node[1] + 1;
                danger[x.first] = cur_node[0] + x.second;
                q1.push({danger[x.first], dist[x.first], x.first});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, c;
    cin >> n >> m;
    unordered_map <int, vector <pair <int, int> > > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    vector <int> dist(n + 1, MM), danger(n + 1, MM);
    dist[1] = 0;
    danger[1] = 0;
    dijkstra(1, graph, dist, danger);
    if (dist[n] != MM) cout << danger[n] << " " << dist[n] << "\n";
    else cout << "-1\n";
}
