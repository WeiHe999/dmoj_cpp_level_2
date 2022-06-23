#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b, lo = 1, hi;
    cin >> n >> m;
    hi = n;
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b;
        lo = max(a, lo);
        hi = min(b, hi);
    }
    if (hi - lo + 1 < 0) cout << 0 << "\n";
    else cout << hi - lo + 1 << "\n";
}
