#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map <int, vector <int> > graph, vector <int> start, int n)
{
    
    queue <int> q1;
    vector <int> dist(n + 1, -1);
    for (int x = 0; x < start.size(); x++)
    {
        q1.push(start[x]);
        dist[start[x]] = 0;
    }
    int s;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto a : graph[cur_node])
        {
            if (dist[a] == -1)
            {
                dist[a] = dist[cur_node] + 1;
                s = dist[a];
                q1.push(a);
            }
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, a, b;
    cin >> n >> m;
    unordered_map <int, vector <int> > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    cin >> k;
    vector <int> start(k);
    for (int x = 0; x < k; x++) cin >> start[x];
    cout << bfs(graph, start, n) << "\n";
}
