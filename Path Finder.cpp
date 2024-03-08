#include <bits/stdc++.h>
using namespace std;
const int MM = 1e5+1;

int n, m, k, a, b;
set <pair <int, int> > s1, vis;

void dfs(pair <int, int> cur, vector <int> &cnt)
{
    vis.insert(cur);
    if (cur.second == 1) cnt[1]++;
    if (cur.first == 1) cnt[2]++;
    if (cur.second == m) cnt[3]++;
    if (cur.first == n) cnt[4]++;
    vector <pair <int, int> > op = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (auto x : op)
    {
        int x1 = cur.first + x.first, y1 = cur.second + x.second;
        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && s1.count({x1, y1}) && !vis.count({x1, y1}))
        {
            dfs({x1, y1}, cnt);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> a >> b;
        s1.insert({a, b});
    }
    for (auto x : s1)
    {
        if (vis.count(x)) continue;
        vector <int> cnt(5);
        dfs(x, cnt);
        if ((cnt[1] > 0 && cnt[2] > 0) || (cnt[1] > 0 && cnt[3] > 0) || (cnt[2] > 0 && cnt[4] > 0) || (cnt[3] > 0 && cnt[4] > 0))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
