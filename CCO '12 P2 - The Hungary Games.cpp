#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, vector <pair <int, int> > > &graph, vector <int> &dist, vector <bool> &vis)
{
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q1;
    q1.push({dist[start_node], start_node});
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
    int n, m, a, b, c, s = INT_MAX;
    cin >> n >> m;
    unordered_map <int, vector <pair <int, int> > > graph1, graph2;
    vector <vector <int> > vec1;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        graph1[a].push_back({b, c});
        graph2[b].push_back({a, c});
        vec1.push_back({a, b, c});
    }
    vector <int> dist1(n + 1, INT_MAX), dist2(n + 1, INT_MAX);
    vector <bool> vis1(n + 1, false), vis2(n + 1, false);
    dist1[1] = 0;
    dist2[n] = 0;
    dijkstra(1, graph1, dist1, vis1);
    dijkstra(n, graph2, dist2, vis2);
    for (auto x : vec1) if (dist1[x[0]] < INT_MAX && dist1[n] < INT_MAX && dist1[x[0]] + x[2] + dist2[x[1]] > dist1[n]) s = min(dist1[x[0]] + x[2] + dist2[x[1]], s);
    if (s != INT_MAX) cout << s << "\n";
    else cout << "-1\n";
}
