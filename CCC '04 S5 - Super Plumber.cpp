#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, tmp;
    while (true)
    {
        cin >> r >> c;
        if (r == 0 && c == 0) break;
        vector <vector <char> > grid(r + 1, vector <char>(c + 1));
        vector <vector <int> > memo(r + 1, vector <int>(c + 1, -1)), val(r + 1, vector <int>(c + 1));
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> grid[i][j];
                if (isdigit(grid[i][j])) val[i][j] = grid[i][j] - '0';
            }
        }
        memo[r][1] = val[r][1];
        for (int i = r - 1; i >= 1; i--)
        {
            if (grid[i][1] != '*') memo[i][1] = memo[i + 1][1] + val[i][1];
            else break;
        }
        for (int j = 2; j <= c; j++)
        {
            for (int i = 1; i <= r; i++)
            {
                if (grid[i][j - 1] != '*' && memo[i][j - 1] != -1)
                {
                    tmp = memo[i][j - 1];
                    for (int k = i; k <= r; k++)
                    {
                        if (grid[k][j] != '*')
                        {
                            tmp += val[k][j];
                            memo[k][j] = max(tmp, memo[k][j]);
                        }
                        else break;
                    }
                }
            }
            for (int i = r; i >= 1; i--)
            {
                if (grid[i][j - 1] != '*' && memo[i][j - 1] != -1)
                {
                    tmp = memo[i][j - 1];
                    for (int k = i; k >= 1; k--)
                    {
                        if (grid[k][j] != '*')
                        {
                            tmp += val[k][j];
                            memo[k][j] = max(tmp, memo[k][j]);
                        }
                        else break;
                    }
                }
            }
        }
        cout << memo[r][c] << "\n";
    }
}
