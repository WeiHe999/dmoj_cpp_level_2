#include <bits/stdc++.h>
using namespace std;

long long MM = 1e9 + 1;

long long dijkstra(long long start_node, long long end_node, unordered_map <long long, vector <vector <long long> > > &graph, long long n)
{
    vector <long long> dist(n + 1, MM);
    vector <bool> vis(n + 1, false);
    priority_queue <pair <long long, long long>, vector <pair <long long, long long> >, greater <pair <long long, long long> > > q1;
    q1.push({0, start_node});
    while (!q1.empty())
    {
        pair <long long, long long> cur_node = q1.top();
        q1.pop();
        if (vis[cur_node.second]) continue;
        vis[cur_node.second] = true;
        for (auto x : graph[cur_node.second])
        {
            if (cur_node.first + x[1] < dist[x[0]])
            {
                dist[x[0]] = cur_node.first + x[1];
                q1.push({dist[x[0]], x[0]});
            }
        }
    }
    return dist[end_node];
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, u, v, l, c, s = 0;
    cin >> n >> m;
    unordered_map <long long, vector <vector <long long> > > graph;
    vector <vector <long long> > vec1;
    for (long long i = 1; i <= m; i++)
    {
        cin >> u >> v >> l >> c;
        vec1.push_back({l, c, u, v});
    }
    sort(vec1.begin(), vec1.end());
    for (auto x : vec1)
    {
        long long d1 = dijkstra(x[2], x[3], graph, n);
        graph[x[2]].push_back({x[3], x[0], x[1]});
        graph[x[3]].push_back({x[2], x[0], x[1]});
        long long d2 = dijkstra(x[2], x[3], graph, n);
        if (d2 < d1) s += x[1];
    }
    cout << s << "\n";
}
