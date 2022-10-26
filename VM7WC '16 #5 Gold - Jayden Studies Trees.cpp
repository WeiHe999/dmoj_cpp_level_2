#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, unordered_set <int> > &graph, int cur_node, unordered_set <int> &vis, vector <int> &dist)
{
    vis.insert(cur_node);
    for (auto x : graph[cur_node])
    {
        if (!vis.count(x))
        {
            dist[x] = dist[cur_node] + 1;
            dfs(graph, x, vis, dist);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    unordered_map <int, unordered_set <int> > graph;
    for (int x = 1; x < n; x++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector <int> dist(n + 1);
    unordered_set <int> vis;
    dfs(graph, 1, vis, dist);
    int max_node, maxa = -1;
    for (int x = 1; x <= n; x++)
    {
        if (dist[x] > maxa)
        {
            maxa = dist[x];
            max_node = x;
        }
    }
    vector <int> dist1(n + 1);
    unordered_set <int> vis1;
    dfs(graph, max_node, vis1, dist1);
    maxa = -1;
    for (auto c : dist1) maxa = max(c, maxa);
    cout << maxa << "\n";
}
