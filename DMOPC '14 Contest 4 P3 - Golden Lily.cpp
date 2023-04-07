#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, a, b, tmp;
    cin >> c >> r;
    vector <vector <int> > grid(r + 1, vector <int>(c + 1)), memo(r + 1, vector <int>(c + 1, 1e9));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> grid[i][j];
    cin >> b >> a;
    a++;
    b++;
    memo[1][1] = grid[1][1];
    for (int j = 2; j <= c; j++) memo[1][j] = memo[1][j - 1] + grid[1][j];
    for (int i = 2; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            tmp = memo[i - 1][j];
            for (int k = j; k <= c; k++)
            {
                tmp += grid[i][k];
                memo[i][k] = min(tmp, memo[i][k]);
            }
        }
        for (int j = c; j >= 1; j--)
        {
            tmp = memo[i - 1][j];
            for (int k = j; k >= 1; k--)
            {
                tmp += grid[i][k];
                memo[i][k] = min(tmp, memo[i][k]);
            }
        }
    }
    cout << memo[a][b] << "\n";
}
