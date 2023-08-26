#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n, m, a, b, c;
    cin >> n >> m;
    vector <vector <pair <int, int> > > graph(n + 1);
    vector <int> dist(n + 1);
    vector <bool> vis(n + 1, false);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back(make_pair(b, c));
        graph[b].push_back(make_pair(a, c));
    }
    queue <int> q1;
    q1.push(1);
    dist[1] = INT_MAX;
    while (!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        vis[cur] = false;
        for (auto x : graph[cur])
        {
            if (min(dist[cur], x.second) > dist[x.first])
            {
                dist[x.first] = min(dist[cur], x.second);
                if (!vis[x.first])
                {
                    vis[x.first] = true;
                    q1.push(x.first);
                }
            }
        }
    }
    dist[1] = 0;
    for (int x = 1; x <= n; x++) cout << dist[x] << "\n";
}
