#include <bits/stdc++.h>
using namespace std;

bool topsort(unordered_map <int, unordered_set <int> > &graph, unordered_map <int, int> &indegree, int n)
{
    priority_queue <int, vector <int>, greater <int> > q;
    for (int x = 1; x <= n; x++) if (indegree[x] == 0) q.push(x);
    int counter = 0;
    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        counter++;
        for (auto x : graph[v]) if (--indegree[x] == 0) q.push(x);
    }
    if (counter == n) return true;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    unordered_map <int, unordered_set <int> > graph;
    unordered_map <int, int> indegree;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        if (graph[a].count(b)) continue;
        graph[a].insert(b);
        indegree[b]++;
    }
    if (topsort(graph, indegree, n)) cout << "Y\n";
    else cout << "N\n";
}
