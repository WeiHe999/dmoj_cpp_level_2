#include <bits/stdc++.h>
using namespace std;

void topsort(unordered_map <int, unordered_set <int> > &graph, unordered_map <int, int> &indegree, vector <int> &vec1)
{
    priority_queue <int, vector <int>, greater <int> > q1;
    for (auto x : indegree) if (x.second == 0) q1.push(x.first);
    while (!q1.empty())
    {
        int v = q1.top();
        q1.pop();
        vec1.emplace_back(v);
        for (auto x : graph[v]) if (--indegree[x] == 0) q1.push(x);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, s = 1;
    cin >> m;
    string a, b;
    unordered_map <int, unordered_set <int> > graph;
    unordered_map <string, int> m1;
    unordered_map <int, string> m2;
    unordered_map <int, int> indegree;
    unordered_set <string> s1;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        if (!s1.count(a))
        {
            s1.insert(a);
            m1[a] = s;
            m2[s] = a;
            s++;
        }
        if (!s1.count(b))
        {
            s1.insert(b);
            m1[b] = s;
            m2[s] = b;
            s++;
        }
        graph[m1[b]].insert(m1[a]);
        indegree[m1[a]]++;
        if (!indegree.count(m1[b])) indegree[m1[b]] = 0;
    }
    vector <int> vec1;
    topsort(graph, indegree, vec1);
    for (auto x : vec1) cout << m2[x] << "\n";
}
