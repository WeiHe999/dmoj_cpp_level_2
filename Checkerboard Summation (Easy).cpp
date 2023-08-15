#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, r, c, x, a1, b1, c1, d1;
    cin >> m >> n;
    vector <vector <int> > grid(m + 1, vector <int>(n + 1)), psa(m + 1, vector <int>(n + 1));
    while (true)
    {
        cin >> r >> c >> x;
        if (r == 0 && c == 0 && x == 0) break;
        grid[r][c] = pow(-1, r + c) * x;
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) psa[i][j] = grid[i][j] + psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
    while (true)
    {
        cin >> a1 >> b1 >> c1 >> d1;
        if (a1 == 0 && b1 == 0 && c1 == 0 && d1 == 0) break;
        if ((a1+b1)%2==1) cout << -1 * (psa[c1][d1] - psa[c1][b1 - 1] - psa[a1 - 1][d1] + psa[a1 - 1][b1 - 1]) << "\n";
        else cout << 1 * (psa[c1][d1] - psa[c1][b1 - 1] - psa[a1 - 1][d1] + psa[a1 - 1][b1 - 1]) << "\n";
    }
}
