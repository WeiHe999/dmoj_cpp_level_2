#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, k, a, b, c, d, q, s;
    cin >> n >> m >> k;
    vector <vector <long long> > da(m + 1, vector <long long>(n + 1));
    for (long long i = 1; i <= k; i++)
    {
        cin >> b >> a >> d >> c;
        da[a][b]++;
        if (d < n) da[a][d + 1]--;
        if (c < m) da[c + 1][b]--;
        if (d < n && c < m) da[c + 1][d + 1]++;
    }
    for (long long i = 1; i <= n; i++)
    {
        s = 0;
        for (long long j = 1; j <= m; j++)
        {
            s += da[j][i];
            da[j][i] = s;
        }
    }
    for (long long j = 1; j <= m; j++)
    {
        s = 0;
        for (long long i = 1; i <= n; i++)
        {
            s += da[j][i];
            da[j][i] = s;
        }
    }
    for (long long i = 1; i <= n; i++)
    {
        s = 0;
        for (long long j = 1; j <= m; j++)
        {
            s += da[j][i];
            da[j][i] = s;
        }
    }
    for (long long j = 1; j <= m; j++)
    {
        s = 0;
        for (long long i = 1; i <= n; i++)
        {
            s += da[j][i];
            da[j][i] = s;
        }
    }
    cin >> q;
    for (long long i = 1; i <= q; i++)
    {
        cin >> b >> a >> d >> c;
        cout << da[c][d] - da[c][b - 1] - da[a - 1][d] + da[a - 1][b - 1] << "\n";
    }
}
