#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int w, h, a, b, steps;
    cin >> w >> h >> a >> b >> steps;
    vector <vector <int> > grid;
    vector <int> tmp, pos = {0, a};
    for (int d = 0; d < h; d++)
    {
        tmp = {};
        for (int c = 0; c < w; c++)
        {
            if ((d < b && c < a) || (d >= h - b && c < a) || (d < b && c >= w - a) || (d >= h - b && c >= w - a)) tmp.emplace_back(0);
            else tmp.emplace_back(1);
        }
        grid.push_back(tmp);
    }
    char dir = 'D';
    for (int e = 0; e < steps; e++)
    {
        if (dir == 'D')
        {
            if (pos[1] + 1 < w && grid[pos[0]][pos[1] + 1] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[1]++;
            }
            else if (pos[0] + 1 < h && grid[pos[0] + 1][pos[1]] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[0]++;
            }
            else if (pos[1] - 1 >= 0 && grid[pos[0]][pos[1] - 1] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[1]--;
            }
            else if (pos[0] - 1 >= 0 && grid[pos[0] - 1][pos[1]] == 1)
            {
                dir = 'U';
                grid[pos[0]][pos[1]] = 0;
                pos[0]--;
            }
        }
        else
        {
            if (pos[1] - 1 >= 0 && grid[pos[0]][pos[1] - 1] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[1]--;
            }
            else if (pos[0] - 1 >= 0 && grid[pos[0] - 1][pos[1]] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[0]--;
            }
            else if (pos[1] + 1 < w && grid[pos[0]][pos[1] + 1] == 1)
            {
                grid[pos[0]][pos[1]] = 0;
                pos[1]++;
            }
            else if (pos[0] + 1 < h && grid[pos[0] + 1][pos[1]] == 1)
            {
                dir = 'D';
                grid[pos[0]][pos[1]] = 0;
                pos[0]++;
            }
        }
    }
    cout << pos[1] + 1 << endl << pos[0] + 1 << endl;
}
