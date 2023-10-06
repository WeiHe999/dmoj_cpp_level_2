#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, l, r;
    cin >> n >> q;
    vector <vector <int> > dp1((int)log2(n) + 1, vector <int>(n + 1)), dp2((int)log2(n) + 1, vector <int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        cin >> dp1[0][i];
        dp2[0][i] = dp1[0][i];
    }
    for (int k = 1; k <= log2(n); k++)
    {
        for (int i = 1; i + (1 << k - 1) <= n; i++)
        {
            dp1[k][i] = min(dp1[k - 1][i], dp1[k - 1][i + (1 << k - 1)]);
            dp2[k][i] = max(dp2[k - 1][i], dp2[k - 1][i + (1 << k - 1)]);
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        int k = (int)log2(r - l + 1);
        cout << max(dp2[k][l], dp2[k][r - (1 << k) + 1]) - min(dp1[k][l], dp1[k][r - (1 << k) + 1]) << "\n";
    }
}
