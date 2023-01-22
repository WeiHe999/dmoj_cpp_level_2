#include <bits/stdc++.h>
using namespace std;

void dijkstra(vector <pair <int, int> > vec1, unordered_map <int, vector<pair<int, int> > > &graph, vector <int> &dist, vector <bool> &vis)
{
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q1;
    for (auto p: vec1)
    {
        q1.push({p.second, p.first});
    }
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
    int n, t, a, b, c, k, d, s = INT_MAX;
    cin >> n >> t;
    unordered_map <int, vector<pair<int, int> > > graph;
    for (int x = 0; x < t; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> k;
    vector <pair <int, int> > vec1;
    vector <int> dist(n + 1, INT_MAX);
    vector <bool> vis(n + 1, false);
    for (int x = 0; x < k; x++)
    {
        cin >> a >> b;
        vec1.push_back({a, b});
        dist[a] = b;
    }
    cin >> d;

    dijkstra(vec1, graph, dist, vis);
    cout << dist[d] << endl;
}
