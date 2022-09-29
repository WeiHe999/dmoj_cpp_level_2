#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <char> > grid, pair <int, int> start_node, pair <int, int> end_node)
{
    queue <pair <int, int> > q1;
    vector <vector <int> > s1(51, vector <int>(51)), dist(51, vector <int>(51));
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
            if (a.first >= 1 && a.first < grid.size() && a.second >= 1 && a.second < grid[0].size() &&
            grid[a.first][a.second] != 'X' && !s1[a.first][a.second])
            {
                dist[a.first][a.second] = dist[cur_node.first][cur_node.second] + 1;
                if (dist[a.first][a.second] >= 60) return -1;
                if (a.first == end_node.first && a.second == end_node.second)
                {
                    return dist[a.first][a.second];
                }
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
    int t;
    cin >> t;
    for (int k = 0; k < t; k++)
    {
        int rows, cols;
        cin >> cols >> rows;
        vector <vector <char> > grid(rows + 1, vector <char>(cols + 1));
        pair <int, int> start_node, end_node;
        for (int x = 1; x <= rows; x++)
        {
            for (int y = 1; y <= cols; y++)
            {
                cin >> grid[x][y];
                if (grid[x][y] == 'C') start_node = {x, y};
                if (grid[x][y] == 'W') end_node = {x, y};
            }
        }
        int a = bfs(grid, start_node, end_node);
        if (a == -1) cout << "#notworth\n";
        else cout << a << "\n";
    }
}
