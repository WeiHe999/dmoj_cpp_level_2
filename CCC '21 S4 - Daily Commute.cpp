#include <bits/stdc++.h>
using namespace std;

void dijkstra(int start_node, unordered_map <int, vector <int> > &graph, vector <int> &dist)
{
    priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > q1;
    q1.push({0, start_node});
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.top();
        q1.pop();
        for (auto x : graph[cur_node.second])
        {
            if (cur_node.first + 1 < dist[x])
            {
                dist[x] = cur_node.first + 1;
                q1.push({dist[x], x});
            }
        }
    }
}

const int MM = 1e9;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, w, d, a, b, s = MM;
    cin >> n >> w >> d;
    unordered_map <int, vector <int> > graph;
    for (int x = 0; x < w; x++)
    {
        cin >> a >> b;
        graph[b].emplace_back(a);
    }
    vector <int> dist(n + 1, MM), key(n + 1);
    dist[n] = 0;
    dijkstra(n, graph, dist);
    for (int x = 1; x <= n; x++)
    {
        cin >> a;
        key[x] = a;
    }
    set <pair <int, int> > total;
    for (int c = 1; c <= n; c++) total.insert({dist[key[c]] + c - 1, c});
    for (int x = 0; x < d; x++)
    {
        cin >> a >> b;
        int old1 = dist[key[a]] + a - 1, old2 = dist[key[b]] + b - 1;
        total.erase({old1, a});
        total.erase({old2, b});
        swap(key[a], key[b]);
        total.insert({dist[key[a]] + a - 1, a});
        total.insert({dist[key[b]] + b - 1, b});
        cout << (*total.begin()).first << "\n";
    }
}
