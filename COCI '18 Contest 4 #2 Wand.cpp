#include <bits/stdc++.h>
using namespace std;

void dfs(unordered_map <int, unordered_set <int> > &graph, int cur_node, vector <bool> &vec1)
{
    for (auto x : graph[cur_node])
    {
        if (!vec1[x - 1])
        {
            vec1[x - 1] = true;
            dfs(graph, x, vec1);
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
    vector <bool> vec1(n, false);
    if (graph[1].size() == 0) vec1[0] = true;
    dfs(graph, 1, vec1);
    for (auto x : vec1) cout << x;
    cout << "\n";
}
