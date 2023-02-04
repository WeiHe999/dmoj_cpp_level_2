#include <bits/stdc++.h>
using namespace std;

const int MM = 1e9;

void dijkstra(int start_node, unordered_map <int, vector <int> > &graph, vector <int> &dist)
{
    priority_queue <int, vector <int>, greater <int> > q1;
    q1.push(start_node);
    while (!q1.empty())
    {
        int cur_node = q1.top();
        q1.pop();
        for (auto x : graph[cur_node])
        {
            if (dist[cur_node] + 1 < dist[x])
            {
                dist[x] = dist[cur_node] + 1;
                q1.push(x);
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, a, b, c, d, s = MM;
    cin >> n >> m >> k >> a >> b;
    vector <int> vec1(k);
    for (int x = 0; x < k; x++) cin >> vec1[x];
    unordered_map <int, vector <int> > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> c >> d;
        graph[c].emplace_back(d);
        graph[d].emplace_back(c);
    }
    vector <int> dist1(n + 1, MM), dist2(n + 1, MM);
    dist1[a] = 0;
    dist2[b] = 0;
    dijkstra(a, graph, dist1);
    dijkstra(b, graph, dist2);
    for (auto x : vec1) s = min(dist1[x] + dist2[x], s);
    cout << s << "\n";
}
