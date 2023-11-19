#include <bits/stdc++.h>
using namespace std;


void dfs(long long node, long long &index, vector <long long> &vis, vector <long long> &last, vector <long long> &path, vector <long long> &dist,
unordered_map <long long, vector <pair <long long, long long> > > &graph)
{
    vis[node] = 1;
    path[index] = node;
    last[node] = index;
    index++;
    for (auto x : graph[node])
    {
        if (!vis[x.first])
        {
            dist[x.first] = dist[node] + x.second;
            dfs(x.first, index, vis, last, path, dist, graph);
            path[index] = node;
            last[node] = index;
            index++;
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, c, q;
    cin >> n;
    unordered_map <long long, vector <pair <long long, long long> > >  graph;
    for (long long i = 1; i <= n - 1; i++)
    {
       cin >> a >> b >> c;
       graph[a + 1].push_back({b + 1, c});
       graph[b + 1].push_back({a + 1, c});
    }
    vector <long long> vis(n + 1), last(n + 1), path(2 * n), dist(n + 1), vec1(2 * n);
    long long ind = 1;
    dfs(1, ind, vis, last, path, dist, graph);
  
    for (long long i = 1; i < 2 * n; i++) vec1[i] = dist[path[i]];
    long long n1 = 2*n - 1;
    long long m = log2(n1);
    vector <vector <long long> > st(n1 + 1, vector <long long>(m + 1)), st_ind(n1 + 1, vector <long long>(m + 1));
    for (long long i = 1; i <= n1; i++)
    {
        st[i][0] = vec1[i];
        st_ind[i][0] = i;
    }
    for (long long k = 1; k <= m; k++)
    {
        for (long long i = 1; i + (1 << (k - 1)) <= n1; i++)
        {
            if (st[i][k - 1] <= st[i + (1 << (k - 1))][k - 1])
            {
                st[i][k] = st[i][k - 1];
                st_ind[i][k] = st_ind[i][k - 1];
            }
            else
            {
                st[i][k] = st[i + (1 << (k - 1))][k - 1];
                st_ind[i][k] = st_ind[i + (1 << (k - 1))][k - 1];
            }
        }
    }
 
    cin >> q;
    for (long long i = 1; i <= q; i++)
    {
        cin >> a >> b;
        long long left = min(last[a + 1], last[b + 1]), right = max(last[a + 1], last[b + 1]);
        long long k = log2(right - left + 1);
        long long ind1;
        if (vec1[st_ind[left][k]] > vec1[st_ind[right - (1 << k) + 1][k]]) ind1 = st_ind[right - (1 << k) + 1][k];
        else ind1 = st_ind[left][k];
        long long lca = path[ind1];
        
        cout << dist[a + 1] + dist[b + 1] - 2 * dist[lca] << "\n";
    }
}
