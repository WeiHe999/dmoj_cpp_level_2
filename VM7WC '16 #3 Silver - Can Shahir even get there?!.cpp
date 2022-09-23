#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map <int, unordered_set <int> > graph, int a, int b)
{
    if (a == b) return 0;
    queue <int> q1;
    q1.push(a);
    unordered_set <int> vis;
    vis.insert(a);
    unordered_map <int, int> dist;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto c : graph[cur_node])
        {
            if (!vis.count(c))
            {
                vis.insert(c);
                dist[c] = dist[cur_node] + 1;
                q1.push(c);
                if (c == b) return dist[c];
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, c, d;
    cin >> n >> m >> a >> b;
    unordered_map <int, unordered_set <int> > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> c >> d;
        graph[c].insert(d);
        graph[d].insert(c);
    }
    if (bfs(graph, a, b) == -1) cout << "NO SHAHIR!\n";
    else cout << "GO SHAHIR!\n";
}
