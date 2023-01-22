#include <bits/stdc++.h>
using namespace std;

void dijkstra(long long start_node, unordered_map <long long, unordered_map <long long, long long> > graph, vector <long long> &dist)
{
    priority_queue <pair <long long, long long>, vector <pair <long long, long long> >, greater <pair <long long, long long> > > q1;
    q1.push({0, start_node});
    while (!q1.empty())
    {
        pair <long long, long long> cur_node = q1.top();
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
    long long n, m, b, q, a, d, c;
    cin >> n >> m >> b >> q;
    unordered_map <long long, unordered_map <long long, long long> > graph;
    for (long long x = 0; x < m; x++)
    {
        cin >> a >> d >> c;
        graph[a][d] = c;
        graph[d][a] = c;
    }
    vector <long long> dist(n + 1, LLONG_MAX);
    dist[b] = 0;
    dijkstra(b, graph, dist);
    for (long long x = 0; x < q; x++)
    {
        cin >> a;
        if (dist[a]<LLONG_MAX) cout << dist[a] << "\n";
        else cout << "-1\n";
    }
}
