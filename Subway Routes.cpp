#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}

unordered_map <int, vector <int> > graph;
vector <int> cnt, dist;
int n, a, b, dia = 1, num_ways = 0;

void dfs(int cur, int prev)
{
    for (auto x : graph[cur])
    {
        if (x == prev) continue;
        dfs(x, cur);
        if (dist[cur] + 1 + dist[x] > dia)
        {
            dia = dist[cur] + 1 + dist[x];
            num_ways = cnt[cur] * cnt[x];
        }
        else if (dist[cur] + 1 + dist[x] == dia)
        {
            num_ways += cnt[cur] * cnt[x];
        }
        if (dist[cur] == dist[x] + 1) cnt[cur] += cnt[x];
        else if (dist[cur] < dist[x] + 1)
        {
            cnt[cur] = cnt[x];
            dist[cur] = dist[x] + 1;
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    cnt.resize(n + 1, 1);
    dist.resize(n + 1);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    dfs(1, -1);
    cout << num_ways << "\n";
}
