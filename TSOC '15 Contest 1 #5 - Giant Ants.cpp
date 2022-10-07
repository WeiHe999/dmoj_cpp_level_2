#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map <int, vector <int> > graph, vector <int> start, int n)
{
    queue <int> q1, q2;
    vector <bool> s1(n + 1);
    vector <int> dist(n + 1, -1);
    q1.push(1);
    dist[1] = 0;
    s1[1] = true;
    for (auto x : start)
    {
        q2.push(x);
        s1[x] = true;
    }
    int s = 1;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto a : graph[cur_node])
        {
            if (!s1[a])
            {
                dist[a] = dist[cur_node] + 1;
                if (a == n) return dist[n];
                s1[a] = true;
                q1.push(a);
            }
        }
        if (s % 4 == 0 && s != 0)
        {
            cur_node = q2.front();
            q2.pop();
            for (auto a : graph[cur_node])
            {
                if (!s1[a])
                {
                    s1[a] = true;
                    q2.push(a);
                }
            }
        }
        s++;
    }
    return -1;
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
    int c = bfs(graph, start, n);
    if (c != -1) cout << c << "\n";
    else cout << "sacrifice bobhob314\n";
}
