#include <bits/stdc++.h>
using namespace std;

void topsort(unordered_map <int, unordered_set <int> > &graph, unordered_map <int, int> &indegree, vector <int> &output, int n)
{
    priority_queue <int, vector <int>, greater <int> > q;
    for (int x = 1; x <= n; x++) if (indegree[x] == 0) q.push(x);
    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        output.emplace_back(v);
        for (auto x : graph[v]) if (--indegree[x] == 0) q.push(x);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    unordered_map <int, unordered_set <int> > graph;
    unordered_map <int, int> indegree;
    vector <int> output;
    for (int x = 1; x <= n; x++)
    {
        cin >> a;
        for (int y = 0; y < a; y++)
        {
            cin >> b;
            graph[b].insert(x);
            indegree[x]++;
        }
    }
    topsort(graph, indegree, output, n);
    for (auto x : output) cout << x << " ";
    cout << "\n";
}
