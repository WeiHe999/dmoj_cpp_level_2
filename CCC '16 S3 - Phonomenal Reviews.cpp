#include <bits/stdc++.h>
using namespace std;

void dfs(int start_node, unordered_map <int, unordered_set <int> > &graph, unordered_map <int, unordered_set <int> > &m1,
unordered_set <int> &s1, vector <bool> &visited, vector <bool> &flag)
{
    visited[start_node] = true;
    if (s1.count(start_node)) flag[start_node] = true;
    for (auto x : graph[start_node])
    {
        if (!visited[x])
        {
            dfs(x, graph, m1, s1, visited, flag);
            if (flag[x]) flag[start_node] = true;
            if (flag[x]) 
            {
                m1[start_node].insert(x);
                m1[x].insert(start_node);
            }
        }
    }
}

void dfs2(int cur_node, unordered_map <int, unordered_set <int> > &graph, vector <bool> &vis, vector <int> &dist)
{
    vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x])
        {
            dist[x] = dist[cur_node] + 1;
            dfs2(x, graph, vis, dist);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, random, s = 0;
    cin >> n >> m;
    unordered_set <int> s1;
    unordered_map <int, unordered_set <int> > graph, m1;
    for (int x = 0; x < m; x++)
    {
        cin >> a;
        s1.insert(a);
        random = a;
    }
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        graph[a].insert(b);
        graph[b].insert(a);
    }
    vector <bool> visited(n, false), vis(n, false), vis2(n, false);
    vector <int> dist(n), dist2(n);
    visited[random] = true;
    vector <bool> flag(n, false);
    dfs(random, graph, m1, s1, visited, flag);
    for (auto x : m1) s += x.second.size();
    dfs2(random, m1, vis, dist);
    int max_num = -1, max_node;
    for (int x = 0; x < n; x++)
    {
        if (dist[x] > max_num)
        {
            max_num = dist[x];
            max_node = x;
        }
    }
    dfs2(max_node, m1, vis2, dist2);
    max_num = -1;
    for (auto x : dist2) max_num = max(x, max_num);
    cout << s - max_num << "\n";
}
