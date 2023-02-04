#include <bits/stdc++.h>
using namespace std;

int MM = 1e9;

void bfs(pair <int, int> start_node, vector <vector <char> > grid, vector <vector <int> > &dist, set <pair <int, int> > camera)
{
    queue <pair <int, int> > q1;
    q1.push(start_node);
    dist[start_node.first][start_node.second] = 0;
    vector <vector <bool> > vis(grid.size() + 1, vector <bool>(grid[0].size() + 1, false));
    vis[start_node.first][start_node.second] = true;
    // init bfs
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > ops = {{cur_node.first + 1, cur_node.second}, {cur_node.first - 1, cur_node.second},
        {cur_node.first, cur_node.second + 1}, {cur_node.first, cur_node.second - 1}};
        // operations
        for (auto x : ops)
        {
            if (x.first < 1 || x.first >= grid.size() || x.second < 1 || x.second >= grid[0].size() || vis[x.first][x.second]) continue;
            int afterx = x.first, aftery = x.second;
            // conveyor
            while (grid[afterx][aftery] == 'L' || grid[afterx][aftery] == 'R' || grid[afterx][aftery] == 'U' || grid[afterx][aftery] == 'D')
            {
                if (vis[afterx][aftery]) break;
                vis[afterx][aftery] = true;
                if (grid[afterx][aftery] == 'L') aftery--;
                else if (grid[afterx][aftery] == 'R') aftery++;
                else if (grid[afterx][aftery] == 'D') afterx++;
                else if (grid[afterx][aftery] == 'U') afterx--;
            }
            if (grid[afterx][aftery] == 'W' || camera.count({afterx, aftery}) || vis[afterx][aftery]) continue;
            dist[afterx][aftery] = dist[cur_node.first][cur_node.second] + 1;
            q1.push({afterx, aftery});
            vis[afterx][aftery] = true;
            // push rest
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <vector <char> > grid(n + 1, vector <char>(m + 1));
    vector <pair <int, int> > vec1;
    set <pair <int, int> > camera;
    pair <int, int> start_node;
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= m; y++)
        {
            cin >> grid[x][y];
            if (grid[x][y] == 'S') start_node = {x, y};
            if (grid[x][y] == 'C')
            {
                vec1.push_back({x, y});
                camera.insert({x, y});
            }
        }
    }
    for (auto x : vec1)
    {
        for (int a = x.first; a > 0; a--)
        {
            if (grid[a][x.second] == 'W') break;
            camera.insert({a, x.second});
        }
        for (int a = x.first; a < grid.size(); a++)
        {
            if (grid[a][x.second] == 'W') break;
            camera.insert({a, x.second});
        }
        for (int a = x.second; a > 0; a--)
        {
            if (grid[x.first][a] == 'W') break;
            camera.insert({x.first, a});
        }
        for (int a = x.second; a < grid[0].size(); a++)
        {
            if (grid[x.first][a] == 'W') break;
            camera.insert({x.first, a});
        }
    }
    bool flag = false;
    if (camera.count({start_node.first, start_node.second})) flag = true;
    vector <vector <int> > dist(n + 1, vector <int>(m + 1, MM));
    bfs(start_node, grid, dist, camera);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (grid[i][j] == '.')
            {
                if (flag)
                {
                    cout << "-1\n";
                    continue;
                }
                if (dist[i][j] != MM) cout << dist[i][j] << "\n";
                else cout << "-1\n";
            }
        }
    }
}
