#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map <int, vector <int> > graph, int n)
{
    queue <int> q1;
    q1.push(1);
    unordered_set <int> vis;
    vis.insert(1);
    unordered_map <int, int> dist = {{1, 0}};
    int s = -1;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        if (!graph.count(cur_node) && s == -1) s = dist[cur_node] + 1;
        q1.pop();
        for (auto a : graph[cur_node])
        {
            if (!vis.count(a))
            {
                vis.insert(a);
                dist[a] = dist[cur_node] + 1;
                q1.push(a);
            }
        }
    }
    if (vis.size() == n) cout << "Y\n";
    else cout << "N\n";
    cout << s << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a;
    cin >> n;
    unordered_map <int, vector <int> > graph;
    for (int x = 0; x < n; x++)
    {
        cin >> m;
        for (int y = 0; y < m; y++)
        {
            cin >> a;
            graph[x + 1].emplace_back(a);
        }
    }
    bfs(graph, n);
}
