#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, u, v, w;
    cin >> n;
    unordered_map <int, vector <pair <int, int> > > graph;
    unordered_map <int, int> col;
    vector <int> vec1;
    unordered_set <int> visited;
    for (int x = 1; x < n; x++)
    {
        cin >> u >> v >> w;
        if (x == 1)
        {
            vec1.emplace_back(u);
            col[u] = 0;
            visited.insert(u);
        }
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    for (int x = 0; x < n; x++)
    {
        for (auto a : graph[vec1[x]])
        {
            if (visited.count(a.first)) continue;
            visited.insert(a.first);
            if (a.second % 2 == 0) col[a.first] = col[vec1[x]];
            else col[a.first] = abs(col[vec1[x]] - 1);
            vec1.emplace_back(a.first);
        }
    }
    for (int b = 1; b <= n; b++)
    {
        cout << col[b] << " ";
    }
    cout << "\n";
}
