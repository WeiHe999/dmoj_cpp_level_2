#include <bits/stdc++.h>
using namespace std;

vector <vector <char> > grid;
vector <vector <bool> > vis;

void dfs(pair <int, int> cur)
{
    vis[cur.first][cur.second] = true;
    vector <pair <int, int> > op = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    for (auto x : op)
    {
        int x1 = cur.first + x.first, y1 = cur.second + x.second;
        if (x1 < 1 || x1 >= grid.size() || y1 < 1 || y1 >= grid[0].size() || grid[x1][y1] == '*' || vis[x1][y1]) continue;
        dfs(make_pair(x1, y1));
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, x, y, s = 0;
    cin >> r >> c;
    grid.resize(r + 1, vector <char>(c + 1, '*'));
    vis.resize(r + 1, vector <bool>(c + 1, false));
    for (int i = 1; i <= r; i++) for (int j = 1; j <= c; j++) cin >> grid[i][j];
    cin >> x >> y;
    dfs(make_pair(x + 1, y + 1));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (vis[i][j])
            {
                if (grid[i][j] == 'S') s += 1;
                else if (grid[i][j] == 'M') s += 5;
                else s += 10;
            }
        }
    }
    cout << s << "\n";
}
