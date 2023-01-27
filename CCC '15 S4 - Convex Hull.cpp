#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, vector <vector <int> > > &graph, vector <vector <int> > &dist, int &k)
{
    priority_queue <vector <int>, vector <vector <int> >, greater <vector <int> > > q1;
    q1.push({0, 0, start_node});
    while (!q1.empty())
    {
        vector <int> cur_node = q1.top();
        q1.pop();
        for (auto x : graph[cur_node[2]])
        {
            int new_dist = cur_node[0] + x[1];
            int new_damage = cur_node[1] + x[2];
            if (new_damage < k && new_dist < dist[x[0]][new_damage])
            {
                dist[x[0]][new_damage] = new_dist;
                q1.push({new_dist, new_damage, x[0]});
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k, n, m, c, d, t, h, a, b;
    cin >> k >> n >> m;
    unordered_map <int, vector <vector <int> > > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> c >> d >> t >> h;
        graph[c].push_back({d, t, h});
        graph[d].push_back({c, t, h});
    }
    cin >> a >> b;
    vector <vector <int> > dist(n + 1, vector <int>(k, INT_MAX));
    dist[a][0] = 0;
    dijkstra(a, graph, dist, k);
    int s = INT_MAX;
    for (auto x : dist[b]) s = min(x, s);
    if (s != INT_MAX) cout << s << "\n";
    else cout << "-1\n";
}
