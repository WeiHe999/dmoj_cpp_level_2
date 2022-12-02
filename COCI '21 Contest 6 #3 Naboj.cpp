#include <bits/stdc++.h>
using namespace std;

void topsort(unordered_map <int, unordered_set <int> > &graph, vector <int> &indegree, vector <int> &vec2, bool &flag, int n)
{
    queue <int> q;
    for (int x = 1; x < indegree.size(); x++) if (indegree[x] == 0) q.push(x);
    int counter = 0;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        counter++;
        vec2.emplace_back(v);
        for (auto x : graph[v]) if (--indegree[x] == 0) q.push(x);
    }
    if (counter < n ) flag = true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    vector <bool> vec1(n + 1, false);
    unordered_map <int, unordered_set <int> > graph;
    vector <int> indegree(n + 1), vec2;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        graph[b].insert(a);
        indegree[a]++;
        vec1[a] = true;
    }
    bool flag = false;
    topsort(graph, indegree, vec2, flag, n);
    if (flag) cout << "-1\n";
    else
    {
        cout << vec2.size() << "\n";
        for (auto x : vec2)
        {
            if (vec1[x]) cout << x << " 1\n";
            else cout << x << " 0\n";
        }
    }
}
