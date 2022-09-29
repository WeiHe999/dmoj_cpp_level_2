#include <bits/stdc++.h>
using namespace std;

vector <pair <int, int> > find_pairs(int n)
{
    vector <pair <int, int> > vec1;
    for (int x = 1; x * x <= n; x++)
    {
        if (n % x == 0)
        {
            vec1.push_back({x, n / x});
            if (x != n / x) vec1.push_back({n / x, x});
        }
    }
    return vec1;
}

bool bfs(vector <vector <int> > grid)
{
    if (grid.size() == 2 && grid[0].size() == 2) return 1;
    queue <pair <int, int> > q1;
    vector <vector <int> > s1(1001, vector <int>(1001));
    q1.push({1, 1});
    s1[1][1] = 1;
    unordered_map <int, vector <pair <int, int> > > m1;
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > vec1;
        if (!m1.count(grid[cur_node.first][cur_node.second])) vec1 = find_pairs(grid[cur_node.first][cur_node.second]);
        else vec1 = m1[grid[cur_node.first][cur_node.second]];
        m1[grid[cur_node.first][cur_node.second]] = vec1;
        for (auto a : vec1)
        {
            if (a.first < grid.size() && a.second < grid[0].size() && !s1[a.first][a.second])
            {
                if (a.first == grid.size() - 1 && a.second == grid[0].size() - 1) return 1;
                s1[a.first][a.second] = 1;
                q1.push(a);
            }
        }
    }
    return 0;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, a;
    cin >> m >> n;
    vector <vector <int> > grid(m + 1, vector <int>(n + 1));
    for (int x = 0; x < m; x++) for (int y = 0; y < n; y++) cin >> grid[x + 1][y + 1];
    if (bfs(grid)) cout << "yes\n";
    else cout << "no\n";
}
