#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MM = 400001;

int n, a, b, max_d = 0, max_cnt = 0;
unordered_map <int, vector <int> > graph;
vector <int> dist1(MM), cnt(MM, 1);

void dfs1(int cur, int prev)
{
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs1(x, cur);
        if (dist1[cur] + dist1[x] + 1 > max_d)
        {
            max_d = dist1[cur] + dist1[x] + 1;
            max_cnt = cnt[cur] * cnt[x];
        }
        else if (dist1[cur] + dist1[x] + 1 == max_d) max_cnt += cnt[cur] * cnt[x];
        if (dist1[x] + 1 > dist1[cur])
        {
            dist1[cur] = dist1[x] + 1;
            cnt[cur] = cnt[x];
        }
        else if (dist1[x] + 1 == dist1[cur]) cnt[cur] += cnt[x];
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs1(1, -1);
    cout << max_d + 1 << " " << max_cnt << "\n";
}
