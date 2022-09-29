#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <char> > grid, pair <int, int> start_node, vector <vector <bool> > &global_vis)
{
    queue <pair <int, int> > q1;
    vector <vector <bool> > vis(global_vis.size(), vector <bool>(global_vis[0].size()));
    q1.push(start_node);
    vis[start_node.first][start_node.second] = true;
    int s = 1;
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > vec1 = {{cur_node.first - 1, cur_node.second}, {cur_node.first + 1, cur_node.second},
        {cur_node.first, cur_node.second - 1}, {cur_node.first, cur_node.second + 1}};
        for (auto a : vec1)
        {
            if (a.first >= 1 && a.first < grid.size() && a.second >= 1 && a.second < grid[0].size() && !vis[a.first][a.second] && grid[a.first][a.second] == '.')
            {
                s++;
                vis[a.first][a.second] = true;
                global_vis[a.first][a.second] = true;
                q1.push(a);
            }
        }
    }
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int wood, rows, cols, rooms = 0;
    cin >> wood >> rows >> cols;
    vector <vector <char> > grid(rows + 1, vector <char>(cols + 1));
    for (int x = 1; x <= rows; x++) for (int y = 1; y <= cols; y++) cin >> grid[x][y];
    vector <vector <bool> > global_vis(rows + 1, vector <bool>(cols + 1));
    vector <int> vec1;
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= cols; j++)
        {
            if (grid[i][j] == '.' && !global_vis[i][j])
            {
                global_vis[i][j] = true;
                vec1.emplace_back(bfs(grid, {i, j}, global_vis));
            }
        }
    }
    sort(vec1.rbegin(), vec1.rend());
    for (auto a : vec1)
    {
        if (wood - a < 0) break;
        else
        {
            wood -= a;
            rooms++;
        }
    }
    if (rooms != 1) cout << rooms << " rooms, " << wood << " square metre(s) left over\n";
    else cout << rooms << " room, " << wood << " square metre(s) left over\n";
}
