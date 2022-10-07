#include <bits/stdc++.h>
using namespace std;

int bfs(vector <vector <char> > grid, int rows, int cols)
{
    if (grid[rows - 1][cols - 1] == '*') return -1;
    queue <pair <int, int> > q1;
    vector <vector <int> > dist(rows, vector <int>(cols, -1));
    q1.push({0, 0});
    dist[0][0] = 1;
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > vec1;
        if (grid[cur_node.first][cur_node.second] == '+') vec1 = {{cur_node.first - 1, cur_node.second}, {cur_node.first + 1, cur_node.second},
        {cur_node.first, cur_node.second - 1}, {cur_node.first, cur_node.second + 1}};
        if (grid[cur_node.first][cur_node.second] == '-') vec1 = {{cur_node.first, cur_node.second - 1}, {cur_node.first, cur_node.second + 1}};
        if (grid[cur_node.first][cur_node.second] == '|') vec1 = {{cur_node.first - 1, cur_node.second}, {cur_node.first + 1, cur_node.second}};
        for (auto a : vec1)
        {
            if (a.first < 0 || a.first >= rows || a.second < 0 || a.second >= cols || dist[a.first][a.second] != -1 || grid[a.first][a.second] == '*') continue;
            dist[a.first][a.second] = dist[cur_node.first][cur_node.second] + 1;
            q1.push(a);
        }
    }
    return dist[rows - 1][cols - 1];
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int rows, cols;
        cin >> rows >> cols;
        vector <vector <char> > grid(rows, vector <char>(cols));
        for (int x = 0; x < rows; x++) for (int y = 0; y < cols; y++) cin >> grid[x][y];
        cout << bfs(grid, rows, cols) << "\n";
    }
}
