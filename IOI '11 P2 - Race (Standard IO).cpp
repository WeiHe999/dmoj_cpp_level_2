#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MM = 2e5 + 2;
unordered_map <int, vector <pair <int, int> > > graph;
map <int, int> m1; //{distance_to_centroid: min_num_steps_to_centroid}
vector <bool> removed(MM);
vector <int> size1(MM), dist(MM), dist2(MM);
int n, a, b, c, k, centroid = -1, cnt = 0, ans = 1e9;

void dfs1(int cur, int prev)
{
    size1[cur] = 1;
    for (auto x : graph[cur])
    {
        if (x.first == prev || removed[x.first]) continue;
        dfs1(x.first, cur);
        size1[cur] += size1[x.first];
    }
}

void dfs2(int cur, int prev, int n)
{
    bool flag = true;
    for (auto x : graph[cur])
    {
        if (x.first == prev || removed[x.first]) continue;
        if (size1[x.first] * 2 > n) 
        {
            dfs2(x.first, cur, n);
            flag = false;
        }
    }
    if (flag)
    {
        centroid = cur;
        removed[centroid] = true;
    }
}

void dfs3(int cur, int prev, vector <pair<int, int> > &vec1)
{
    int d = dist[cur];
    if (d > k) return;
    if (!m1.count(d)) vec1.push_back({d, dist2[cur]});
    else
    {
        if (dist2[cur] < m1[d] && dist2[cur] < k) vec1.push_back({d, dist2[cur]});
    }
    if (m1.count(k - d))
    {
      ans = min(ans, dist2[cur] + m1[k-d]); 
    }
    for (auto x : graph[cur])
    {
        if (x.first == prev || removed[x.first]) continue;
        dist[x.first] = dist[cur] + x.second;
        dist2[x.first] = dist2[cur] + 1;
        dfs3(x.first, cur, vec1);
    }
}

void dfs4(int cur)
{
    dfs1(cur, -1);
    dfs2(cur, -1, size1[cur]);
    m1 = {{0, 0}};
    dist[centroid] = 0;
    dist2[centroid] = 0;
    for (auto x : graph[centroid])
    {
        if (removed[x.first]) continue;
        vector <pair<int, int> >  vec1;
        dist[x.first] = x.second;
        dist2[x.first] = 1;
        dfs3(x.first, centroid, vec1);
        for (auto y : vec1) 
        {
            if (m1.count(y.first)) m1[y.first] = min(m1[y.first], y.second);
            else m1[y.first] = y.second;
        }
    }
    for (auto x : graph[centroid])
    {
        if (removed[x.first]) continue;
        dfs4(x.first);
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    dfs4(0);
    if (ans < 1e9) cout << ans << endl;
    else cout << -1 << endl;
}
