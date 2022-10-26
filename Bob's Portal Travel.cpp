#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, int> &graph, int cur_node, vector <int> &vis, vector <int> &dist, int &size, int &start, bool &flag)
{
    if (flag) return;
    vis[cur_node] = 1;
    int x = graph[cur_node];
    if (vis[x] == 1)
    {
        start = x;
        size = dist[cur_node] - dist[x] + 1;
        flag = true;
        return;
    }
    else if (vis[x] == 0)
    {
        dist[x] = dist[cur_node] + 1;
        dfs(graph, x, vis, dist, size, start, flag);
    }
    vis[cur_node] = 2;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    long long m;
    cin >> n >> m;
    unordered_map <int, int> graph;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        graph[x + 1] = a;
    }
    vector <int> vis(n + 1), dist(n + 1);
    int size = 0, start = -1;
    bool flag = false;
    dfs(graph, 1, vis, dist, size, start, flag);
    int cur;
    if (dist[start] > m)
    {
        cur = 1;
    }
    else
    {
        m -= dist[start];
        m = m % size;
        cur = start;
    }
    for (int x = 0; x < m; x++) cur = graph[cur];
    cout << cur << "\n";
}
