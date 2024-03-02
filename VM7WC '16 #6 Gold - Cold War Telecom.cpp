#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5;

unordered_map <int, vector <int> > graph, graph2;
unordered_map <int, vector <int> > components;
vector <int> dfn(MM + 1), low(MM + 1), in_stack(MM + 1), roots(MM + 1), ar(MM + 1);
stack <int> s1;
int ind = 0;

void tarjan(int cur, int prev)
{
    ind++;
    dfn[cur] = low[cur] = ind;
    s1.push(cur);
    in_stack[cur] = 1;
    int cnt = 0;
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        if (dfn[x] == 0)
        {
            tarjan(x, cur);
            low[cur] = min(low[cur], low[x]);
            if (dfn[cur] <= low[x] && prev != -1) ar[cur] = 1;
            cnt++;
        }
        else if (in_stack[x]) low[cur] = min(low[cur], dfn[x]);
    }
    if (cnt >= 2 && prev == -1) ar[cur] = 1;
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

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    tarjan(1, -1);
    vector <int> vec1;
    for (int i = 1; i <= n; i++) if (ar[i] == 1) vec1.emplace_back(i);
    cout << vec1.size() << "\n";
    for (auto x : vec1) cout << x << "\n";
}
