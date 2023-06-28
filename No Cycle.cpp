#include <bits/stdc++.h>
using namespace std;

unordered_map <int, int> indegree, m1;
unordered_map <int, vector <int> > graph;
vector <int> vis(100001, false);

vector <int> top_sort()
{
    vector <int> output;
    queue <int> q1;
    for (auto x : indegree) if (!x.second) q1.push(x.first);
    bool flag = false;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        if (vis[cur_node])
        {
            flag = true;
            break;
        }
        output.emplace_back(cur_node);
        vis[cur_node] = true;
        for (auto x : graph[cur_node]) if (!(--indegree[x])) q1.push(x);
    }
    if (flag) output = {};
    return output;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, a, b;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        indegree[b]++;
        graph[a].emplace_back(b);
    }
    for (int i = 1; i <= n; i++) if (!indegree.count(i)) indegree[i] = 0;
    vector <int> output = top_sort();
    if (!output.size())
    {
        cout << "-1\n";
        return 0;
    }
    for (int i = 1; i <= n; i++) m1[output[i]] = i;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        if (m1[a] < m1[b]) cout << a << " " << b << "\n";
        else cout << b << " " << a << "\n";
    }
}
