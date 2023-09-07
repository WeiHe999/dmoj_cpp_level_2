#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b, c, k, s = 0, ans = 0;
    cin >> a >> b >> c >> k;
    if (s + a <= k)
    {
        ans += a;
        s += a;
    }
    else
    {
        ans += k - s;
        s = k;
    }
    if (s + b <= k) s += b;
    else s = k;
    if (s + c <= k)
    {
        ans -= c;
        s += c;
    }
    else
    {
        ans -= k - s;
        s = k;
    }
    cout << ans << "\n";
}
