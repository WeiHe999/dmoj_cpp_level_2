#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;

unordered_map <int, vector <int> > graph;
vector <int> indegree(MM), c(MM, -1);
vector <bool> vis(MM, false);

void colour(int cur)
{
    unordered_set <int> blacklist;
    for (auto x : graph[cur]) blacklist.insert(c[x]);
    int ind = 1;
    while (blacklist.count(ind)) ind++;
    c[cur] = ind;
}

void dfs(int cur)
{
    colour(cur);
    vis[cur] = true;
    for (auto x : graph[cur])
    {
        if (!vis[x])
        {
            dfs(x);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, k = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        indegree[a]++;
        indegree[b]++;
    }
    for (int i = 1; i <= n; i++) k = max(indegree[i], k);
    if (k % 2 == 0) k++;
    cout << k << "\n";
    dfs(1);
    for (int i = 1; i <= n; i++) cout << c[i] << "\n";
}
