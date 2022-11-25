#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, unordered_set <int> > &graph, int cur_node, vector <bool> &vis, int &cur)
{
    vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x])
        {
            cur = max(x, cur);
            dfs(graph, x, vis, cur);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    unordered_map <int, unordered_set <int> > graph;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        graph[b].insert(a);
    }
    vector <bool> vis(n + 1, false);
    int max1 = -1, max2;
    for (int k = n; k > 0; k--)
    {
        int cur = -1;
        dfs(graph, k, vis, cur);
        if (cur > max1)
        {
            max1 = cur;
            max2 = k;
        }
        if (vis.size() == n) break;
    }
    if (max1 == -1) cout << "-1\n";
    else cout << max1 << " " << max2 << "\n";
}
