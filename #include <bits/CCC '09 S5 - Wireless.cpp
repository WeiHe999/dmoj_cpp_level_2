#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, k, x, y, r, b, s = -1, cnt = 0, sum;
    cin >> m >> n >> k;
    vector <vector <int> > da(30001, vector <int>(1001));
    for (int i = 0; i < k; i++)
    {
        cin >> y >> x >> r >> b;
        for (int s = max(1, x - r); s <= min(m, x + r); s++)
        {
            da[s][max(1, (int)ceil(y - sqrt(r * r - (s - x) * (s - x))))] += b;
            da[s][min(n, (int)floor(y + sqrt(r * r - (s - x) * (s - x)))) + 1] -= b;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            sum += da[i][j];
            if (sum == s) cnt++;
            if (sum > s)
            {
                s = sum;
                cnt = 1;
            }
        }
    }
    cout << s << "\n" << cnt << "\n";
}
