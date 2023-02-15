#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, k, a, b;
    cin >> r >> c >> k;
    vector <vector <int> > grid(r + 1, vector <int>(c + 1));
    vector <vector <bool> > fixed(r + 1, vector <bool>(c + 1, false));
    for (int x = 0; x < k; x++)
    {
        cin >> a >> b;
        fixed[a][b] = true;
    }
    grid[1][1] = 1;
    fixed[1][1] = true;
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) if (!fixed[i][j]) grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
    cout << grid[r][c] << "\n";
}
