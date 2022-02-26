#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <vector <int> > grid(n, vector <int>(n));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < n; y++)
        {
            cin >> a;
            grid[x][y] = a;
        }
    }
    int maxa = INT_MIN, maxn = 0;
    for (int b = 0; b < grid.size(); b++)
    {
        for (int c = 0; c < grid[0].size(); c++)
        {
            if (b != 0 && c != 0)
            {
                if (grid[b][c] == 0) continue;
                grid[b][c] = min(min(grid[b - 1][c], grid[b - 1][c - 1]), grid[b][c - 1]) + 1;
            }
            if (maxa < grid[b][c])
            {
                maxa = grid[b][c];
                maxn = 0;
            }
            if (maxa == grid[b][c]) maxn++;
        }
    }
    cout << maxa * maxn << endl;
}
