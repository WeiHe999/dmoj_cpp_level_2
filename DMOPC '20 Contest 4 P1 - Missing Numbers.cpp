#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, n, s, diff, mid, ans;
    cin >> t;
    for (long long x = 0; x < t; x++)
    {
        cin >> n >> s;
        diff = ((n + 1) * n) / 2 - s;
        mid = diff / 2;
        if (diff % 2 == 0) ans = min(mid - 1, n - mid);
        else ans = min(mid, n - mid);
        cout << ans << endl;
    }
}
