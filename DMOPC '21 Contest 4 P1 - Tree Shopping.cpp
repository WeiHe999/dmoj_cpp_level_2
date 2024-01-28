#include <bits/stdc++.h>
using namespace std;
#define int long long

bool check(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y)
{
    if ((x >= min(x1, x3)) && (x <= max(x1, x3)) && (y >= min(y1, y2)) && (y <= max(y1, y2)) && (abs(y3 - y2) * abs(x - x2) <= abs(x3 - x2) * abs(y - y2))) return true;
    return false;
}

int32_t main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q, a, b, c, d, e, f, x, y;
    cin >> n >> q;
    vector <vector <int> > vec1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d >> e >> f;
        vec1.push_back({a, b, c, d, e, f});
    }
    for (int i = 1; i <= q; i++)
    {
        int cnt = 0;
        cin >> x >> y;
        for (auto w : vec1)
        {
            if (check(w[0], w[1], w[2], w[3], w[4], w[5], x, y)) cnt++;
        }
        cout << cnt << "\n";
    }
}
