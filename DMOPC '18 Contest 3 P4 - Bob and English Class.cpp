#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MM = 2e5+3;
int sz[MM], students[MM], dist[MM], centroid = -1;;
unordered_map <int, vector <pair<int, int> > > graph;

int k, n, a, b, c;

void dfs(int cur, int prev)
{
    sz[cur] = students[cur];
    for (auto x : graph[cur])
    {
        if (x.first == prev) continue;
        dfs(x.first, cur);
        sz[cur] += sz[x.first];
    }
}

void dfs2(int cur, int prev)
{
    bool flag = true;
    for (auto x : graph[cur])
    {
        if (x.first == prev) continue;
        if (sz[x.first] > k/2) 
        {
            flag = false;
            dfs2(x.first, cur);
        }
    }
    if (flag) centroid = cur;
}

void dfs3(int cur, int prev)
{
    for (auto x : graph[cur])
    {
        if (x.first == prev) continue;
        dist[x.first] = dist[cur] + x.second;
        dfs3(x.first, cur);
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    memset(sz, 0, sizeof(sz));
    memset(students, 0, sizeof(students));
    memset(dist, 0, sizeof(dist));
    cin >> k >> n;
    for (int i = 1; i <= k; i++)
    {
        cin >> a;
        students[a]++;
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b >> c;
        graph[a].emplace_back(make_pair(b, c));
        graph[b].emplace_back(make_pair(a, c));
    }
    dfs(1, -1);
    cout << endl;
    
    dfs2(1, -1);

    dfs3(centroid, -1);

    int ans = 0;
    for (int i=1; i<=n; i++) ans += students[i] * dist[i];
    cout << ans << endl;
    

}
