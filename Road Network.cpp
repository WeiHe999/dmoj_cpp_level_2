#include <bits/stdc++.h>
using namespace std;

long long distance(long long x1, long long y1, long long x2, long long y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

void dfs(unordered_map <long long, unordered_set <long long> > &graph, long long start_node, unordered_set <long long> &visited)
{
    visited.insert(start_node);
    for (auto x : graph[start_node]) if (!visited.count(x)) dfs(graph, x, visited);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, a, b;
    cin >> n >> m;
    unordered_set <long long> all_nodes, single_nodes, tree_set;
    unordered_map <long long, pair <long long, long long> > m1;
    unordered_map <long long, unordered_set <long long> > graph;
    vector <vector <long long> > dist(n + 1, vector <long long>(n + 1));
    for (long long x = 1; x <= n; x++)
    {
        all_nodes.insert(x);
        single_nodes.insert(x);
        cin >> a >> b;
        m1[x] = {a, b};
    }
    for (long long x = 0; x < m; x++)
    {
        cin >> a >> b;
        if (single_nodes.count(a)) single_nodes.erase(a);
        if (single_nodes.count(b)) single_nodes.erase(b);
        graph[a].insert(b);
        graph[b].insert(a);
    }
    for (auto i : all_nodes)
    {
        for (auto j : all_nodes)
        {
            long long d = distance(m1[i].first, m1[i].second, m1[j].first, m1[j].second);
            dist[i][j] = d;
            dist[j][i] = d;
        }
    } 
    long long first_node = *single_nodes.begin();
    tree_set.insert(first_node);
    all_nodes.erase(first_node);
    double s = 0;
    while (tree_set.size() < n)
    {
        long long min_dist = LLONG_MAX, min_node;
        for (auto x : tree_set)
        {
            for (auto y : all_nodes)
            {
                long long a = dist[x][y];
                if (a <= min_dist)
                {
                    min_dist = a;
                    min_node = y;
                }
            }
        }
        s += sqrt(min_dist); 
        if (single_nodes.count(min_node))
        {
           tree_set.insert(min_node);
           all_nodes.erase(min_node);
        }
        else
        {
            unordered_set <long long> visited;
            dfs(graph, min_node, visited);
            for (auto h: visited)
            {
                tree_set.insert(h);
                all_nodes.erase(h);
            }
        }
    }
    cout << fixed << setprecision(2) << s << "\n";
}
