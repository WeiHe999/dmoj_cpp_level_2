#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int c, r, d, a, b, w;
    cin >> c >> r >> d;
    unordered_map <int, vector <pair <int, int> > > graph;
    for (int x = 0; x < r; x++)
    {
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w});
    }
    unordered_set <int> destinations;
    for (int x = 0; x < d; x++)
    {
        cin >> a;
        destinations.insert(a);
    }
    vector <int> dist(c + 1);
    vector <bool> vis(c + 1, false);
    priority_queue <pair <int, int> > q1;
    q1.push({INT_MAX, 1});
    dist[1] = INT_MAX;
    while (!q1.empty())
    {
        pair <int, int> f = q1.top();
        q1.pop();
        if (vis[f.second]) continue;
        vis[f.second] = true;
        for (auto x : graph[f.second])
        {
            if (!vis[x.first] && x.second > dist[x.first])
            {
                q1.push({x.second, x.first});
                dist[x.first] = x.second;
            }
        }
    }
    int minimum = INT_MAX;
    for (auto e : destinations) minimum = min(dist[e], minimum);
    cout << minimum << "\n";
}
