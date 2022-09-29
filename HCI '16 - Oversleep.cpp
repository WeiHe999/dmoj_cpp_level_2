#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <char> > grid, pair <int, int> start_node, pair <int, int> end_node)
{
    queue <pair <int, int> > q1;
    vector <vector <int> > s1(1001, vector <int>(1001)), dist(1001, vector <int>(1001));
    q1.push(start_node);
    s1[start_node.first][start_node.second] = 1;
    dist[start_node.first][start_node.second] = 0;
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > vec1 = {{cur_node.first - 1, cur_node.second}, {cur_node.first + 1, cur_node.second},
        {cur_node.first, cur_node.second - 1}, {cur_node.first, cur_node.second + 1}};
        for (auto a : vec1)
        {
            if (a.first >= 1 && a.first < grid.size() && a.second >= 1 && a.second < grid[0].size() && grid[a.first][a.second] != 'X' && !s1[a.first][a.second])
            {
                dist[a.first][a.second] = dist[cur_node.first][cur_node.second] + 1;
                if (a.first == end_node.first && a.second == end_node.second) return dist[a.first][a.second] - 1;
                s1[a.first][a.second] = 1;
                q1.push(a);
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char> > grid(n + 1, vector <char>(m + 1));
    pair <int, int> start_node, end_node;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            cin >> grid[x][y];
            if (grid[x][y] == 's') start_node = {x, y};
            if (grid[x][y] == 'e') end_node = {x, y};
        }
    }
    cout << bfs(grid, start_node, end_node) << "\n";
}
