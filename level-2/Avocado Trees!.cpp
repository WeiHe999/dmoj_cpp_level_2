#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, h, a, b, l, r, s = 0;
    cin >> n >> q >> h;
    vector <int> psa = {0};
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        if (a <= h) psa.emplace_back(psa.back() + b);
        else psa.emplace_back(psa.back());
    }
    for (int y = 0; y < q; y++)
    {
        cin >> l >> r;
        s = max(psa[r] - psa[l - 1], s);
    }
    cout << s << endl;
}
