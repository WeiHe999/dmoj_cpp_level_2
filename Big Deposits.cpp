#include <bits/stdc++.h>
using namespace std;


bool check(long long s, long long p, long long y, long long t)
{
    long long x = 0;
    for (long long z = 0; z < y; z++)
    {
        x += s;
        x = x + x*p/100;
        if (x >= t) return true;
    }
    if (x >= t) return true;
    else return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long p, y, t;
    cin >> p >> y >> t;
    long long l = 0, r = 10000000000000000+1, m, ans = LLONG_MAX;
    while (l <= r)
    {
        m = (l + r) / 2;
        if (check(m, p, y, t))
        {
            r = m - 1;
            ans = m;
        }
        else l = m + 1;
    }
    cout << ans << endl;
}
