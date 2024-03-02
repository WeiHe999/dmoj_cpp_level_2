#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6;

unordered_map <int, vector <int> > graph, graph2;
//unordered_map <int, vector <int> > components;
vector <int> dfn(MM + 1), low(MM + 1), fun(MM + 1);
vector <bool> vis(MM + 1, false);
unordered_set<int> in_stack;
vector <pair <int, int> > component_root(MM + 1);
stack <int> s1;
int ind = 0;

void tarjan(int cur)
{
    ind++;
    dfn[cur] = low[cur] = ind;
    s1.push(cur);
    in_stack.insert(cur);
    //in_stack[cur] = 1;
    for (auto x : graph[cur])
    {
        if (dfn[x] == 0)
        {
            tarjan(x);
            low[cur] = min(low[cur], low[x]);
        }
        else if (in_stack.count(x)) low[cur] = min(low[cur], dfn[x]);
    }
    if (dfn[cur] == low[cur])
    {
        vector <int> vec1;
        while (s1.top() != cur)
        {
            vec1.emplace_back(s1.top());
            in_stack.erase(s1.top());
            s1.pop();
        }
        int rt = s1.top();
        vec1.emplace_back(s1.top());
        int tot_f = 0;
        for (auto x: vec1) 
        {
            tot_f += fun[x];
        }
        for (auto x: vec1) 
        {
            component_root[x] = {rt, tot_f};
        }
        
        //components[s1.top()] = vec1;
        in_stack.erase(s1.top());
        s1.pop();
    }
}

void dijkstra(int start_node, vector <int> & dist)
{
    priority_queue <pair <int, int> > pq;
    dist[start_node] = component_root[start_node].second;
    pq.push({dist[start_node], start_node});
    while (!pq.empty())
    {
        pair <int, int> cur = pq.top();
        pq.pop();
        if (vis[cur.second]) continue;
        vis[cur.second] = true;
        for (auto x : graph2[cur.second])
        {
            if (cur.first + component_root[x].second >= dist[x])
            {
                dist[x] = cur.first + component_root[x].second;
                pq.push({dist[x], x});
            }
        }
    }
}

int main() {
    int n, m, s, e, a, b;
    cin >> n >> m >> s >> e;
    for (int i = 1; i <= n; i++) cin >> fun[i];
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
    }
    tarjan(s);
    dfn.clear();
    fun.clear();
    vis.clear();
    // for (auto x : components)
    // {
    //     int sum = 0;
    //     for (auto y : x.second)
    //     {
    //         sum += fun[y];
    //         if (e == y) e = x.first;
    //         if (s == y) s = x.first;
    //     }
    //     for (auto y : x.second) component_root[y] = {x.first, sum};
    // }
    e = component_root[e].first;
    s = component_root[s].first;
    
    for (auto x : graph) for (auto y : x.second) if (component_root[x.first].first != component_root[y].first) graph2[component_root[x.first].first].emplace_back(component_root[y].first);
    for (int i=0; i<=n; i++) low[i] = -1;
    dijkstra(s, low);
    cout << low[e] << "\n";
}
