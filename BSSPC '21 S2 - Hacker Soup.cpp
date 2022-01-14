#include <bits/stdc++.h>
using namespace std;

pair <long long, long long> ccw_rotate(long long x, long long y, long long a, long long b, long long n)
{
    x = x - a;
    y = y - b;
    long long x2 = n - y - 1 + a;
    long long y2 = x + b;
    return make_pair(x2, y2);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, q, x1, y1, x2, y2, x, y;
    cin >> n >> k >> q;
    vector <vector <long long> > ops;
    for (long long c = 0; c < k; c++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        ops.push_back({x1 - 1, y1 - 1, x2 - 1, y2 - 1});
    }
    for (long long d = 0; d < q; d++)
    {
        cin >> x >> y;
        x--;
        y--;
        for (long long e = ops.size() - 1; e >= 0; e--)
        {
            if (x >= ops[e][0] && y >= ops[e][1] && x <= ops[e][2] && y <= ops[e][3])
            {
                pair <long long, long long> f = ccw_rotate(x, y, ops[e][0], ops[e][1], ops[e][2] - ops[e][0] + 1);
                x = f.first;
                y = f.second;
            }
        }
        cout << n * x + y + 1 << endl;
    }
}
