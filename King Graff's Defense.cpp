#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+1;

unordered_map <int, vector <int> > graph;
unordered_map <int, int> comp_size;
int dfn[MM], low[MM];
set<pair<int, int> > bridges;
int ind = 0;
int comp_id = 0;

void tarjan(int cur, int prev)
{
    ind++;
    dfn[cur] = low[cur] = ind;
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        if (dfn[x] == 0)
        {
            tarjan(x, cur);
            low[cur] = min(low[x], low[cur]);
            if (low[cur] < low[x]) bridges.insert({min(cur, x), max(cur, x)});
        }
        else
        {
            low[cur] = min(dfn[x], low[cur]);
        }
    }
}

void dfs(int cur)
{
    low[cur] = 1;
    comp_size[comp_id]++;
    for (auto x: graph[cur])
    {
        if (!low[x] && !bridges.count({min(cur, x), max(cur, x)}))
        {
            dfs(x);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    long long n, m, a, b, s = 0;
    cin >> n >> m;
    for (long long i = 1; i <= m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    tarjan(1, -1);
    // for (auto x:bridges)
    // {
    //     cout << x.first << "-->" << x.second << endl;
    // }
    
    memset(low, 0, sizeof(low));
    for (long long i = 1; i <= n; i++)
    {
        if (low[i]==0)
        {
            comp_id++;
            dfs(i);
        }
    }

    for (auto x : comp_size) s += ((x.second * (x.second - 1l)) / 2l);
    long long denominator = (n * (n - 1l)) / 2l;
    double numerator = (denominator - s) * 1.0;
    cout << fixed << setprecision(5) << numerator / denominator << "\n";
}
