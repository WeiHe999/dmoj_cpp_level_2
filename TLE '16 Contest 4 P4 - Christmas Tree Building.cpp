#include <bits/stdc++.h>
using namespace std;


void dfs(unordered_map <long long, vector <pair <long long, long long> > > &graph, long long cur_node, vector <bool> &global_vis, vector <bool> &vis, vector <long long> &dist,
unordered_map <long long, long long> &parents, long long &max_dist, long long &max_node)
{
    vis[cur_node] = true;
    global_vis[cur_node] = true;
    for (auto x : graph[cur_node])
    {
        if (!vis[x.first])
        {
            dist[x.first] = dist[cur_node] + x.second;
            if (dist[x.first] > max_dist)
            {
                max_dist = dist[x.first];
                max_node = x.first;
            }
            parents[x.first] = cur_node;
            dfs(graph, x.first, global_vis, vis, dist, parents, max_dist, max_node);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, q, a, b, c;
    cin >> n >> m >> q;
    unordered_map <long long, vector <pair <long long, long long> > > graph;
    unordered_set<long long> connected_nodes;
    for (long long x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        connected_nodes.insert(a);
        connected_nodes.insert(b);
        
    }
    long long unconnected_nodes = n - connected_nodes.size();
    vector <bool> global_vis(n + 1, false);
    long long ind = 0;
    unordered_map <long long, pair <long long, long long> > results;
    for (auto x: connected_nodes)
    {
        if (!global_vis[x])
        {
            vector <bool> vis(n + 1, false), vis2(n + 1, false);
            vector <long long> dist(n + 1);
            unordered_map <long long, long long> parents = {{x, -1}}, parents2;
            long long max_dist = 0, max_node = x, max_dist2 = 0, max_node2 = x, radius = LLONG_MAX;
            dfs(graph, x, global_vis, vis, dist, parents, max_dist, max_node);
            parents2 = {{max_node, -1}};
            vector <long long> dist2(n + 1);
            dfs(graph, max_node, global_vis, vis2, dist2, parents2, max_dist2, max_node2);
            long long cur = max_node2;
            while (cur != -1)
            {
                radius = min(max(dist2[cur], max_dist2 - dist2[cur]), radius);
                cur = parents2[cur];
            }
            results[ind] = {max_dist2, radius};
            ind++;
        }
    }

    long long s = 0;
    if (q == 1)
    {
        for (auto x : results) s += x.second.first;
        cout << s + (ind - 1 +  unconnected_nodes) << "\n";
    }
    else
    {
        if (results.size()>0)
        {
            vector<long long> v1;
            for (auto p: results) v1.push_back(p.second.second);
            sort(v1.rbegin(), v1.rend());
            if (v1.size()>1 & v1[0]==v1[1]) cout << v1[0]+1 << endl;
            else cout << v1[0] << endl;            
        }
        else cout << 1 << endl;

    }
}
