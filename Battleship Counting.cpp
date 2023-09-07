#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, s = 0;
    cin >> r >> c;
    vector <vector <char> > grid(r + 1, vector <char>(c + 1));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> grid[i][j];
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (grid[i][j] == '.') continue;
            if (i + 1 <= r) grid[i + 1][j] = '.';
            if (j + 1 <= c) grid[i][j + 1] = '.';
            s++;
        }
    }
    cout << s << "\n";
}
