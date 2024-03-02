#include <bits/stdc++.h>
using namespace std;
const int MM = 1000;

unordered_map <int, vector <int> > graph, graph2;
unordered_map <int, vector <int> > components;
vector <int> dfn(MM + 1), low(MM + 1), in_stack(MM + 1), component_root(MM + 1);
stack <int> s1;
int i = 0;

void tarjan(int cur, int prev)
{
    i++;
    dfn[cur] = low[cur] = i;
    s1.push(cur);
    in_stack[cur] = 1;
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        if (dfn[x] == 0)
        {
            tarjan(x, cur);
            low[cur] = min(low[cur], low[x]);
        }
        else if (in_stack[x]) low[cur] = min(low[cur], dfn[x]);
    }
    if (dfn[cur] == low[cur])
    {
        vector <int> vec1;
        while (s1.top() != cur)
        {
            vec1.emplace_back(s1.top());
            in_stack[s1.top()] = 0;
            s1.pop();
        }
        vec1.emplace_back(s1.top());
        components[s1.top()] = vec1;
        in_stack[s1.top()] = 0;
        s1.pop();
    }
}

int main() {
    int n, m, a, b, s = 0;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    tarjan(1, -1);
    for (auto x : components) for (auto y : x.second) component_root[y] = x.first;
    for (auto x : graph)
    {
        for (auto y : x.second)
        {
            if (dfn[x.first] < dfn[y] && low[x.first] < low[y])
            {
                graph2[component_root[x.first]].emplace_back(component_root[y]);
                graph2[component_root[y]].emplace_back(component_root[x.first]);
            }
        }
    }
    for (auto x : graph2) if (x.second.size() == 1) s++;
    cout << ceil(s / 2.0) << "\n";
}
