#include <bits/stdc++.h>
using namespace std;

const int MM = 2e5 + 1;

int n, cnt[MM][2];
vector <pair <int, int> > g[MM];

void dfs(int c, int p, int dep)
{
    cnt[c][dep & 1]++;
    for (auto [to, w] : g[c])
    {
        if (to != p)
        {
            dfs(to, c, dep + w);
            cnt[c][0] += cnt[to][0];
            cnt[c][1] += cnt[to][1];
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (auto i = 0; i < n - 1; i++)
    {
        int a, b, w; cin >> a >> b >> w;
        g[a].emplace_back(b, w & 1);
        g[b].emplace_back(a, w & 1);
    }
    dfs(1, -1, 0);
    auto compute = [&] (int a[2]) { long long paths = (long long)(a[0]) * a[1]; return abs((long long)(n)*(n - 1) / 2 - paths - paths);};
    long long ans = compute(cnt[1]);
    for (auto i = 2; i <= n; i++)
    {
        int cur[2]{cnt[1][0], cnt[1][1]};
        cur[0] += cnt[i][1] - cnt[i][0];
        cur[1] += cnt[i][0] - cnt[i][1];
        ans = min(ans, compute(cur));
    }
    cout << ans << "\n";
}
