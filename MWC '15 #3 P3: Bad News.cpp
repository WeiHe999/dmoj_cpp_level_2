#include <bits/stdc++.h>
using namespace std;

void find_all(int x, int y, string str1, int ind, vector <vector <char> > grid, bool &flag, vector <vector <bool> > visited)
{
    if (ind == str1.size()) flag = true;
    if (flag) return;
    vector <pair <int, int> > pos = {{x - 1, y - 1}, {x, y - 1}, {x + 1, y - 1}, {x - 1, y}, {x + 1, y}, {x - 1, y + 1}, {x, y + 1}, {x + 1, y + 1}};
    for (auto a : pos)
    {
        if (a.first < 0 || a.first >= grid.size() || a.second < 0 || a.second >= grid.size() || grid[a.first][a.second] != str1[ind] || visited[a.first][a.second]) continue;
        vector <vector <bool> > visited2 = visited;
        visited2[a.first][a.second] = true;
        find_all(a.first, a.second, str1, ind + 1, grid, flag, visited2);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q;
    string str1;
    cin >> n >> q;
    vector <vector <char> > grid(n, vector <char>(n));
    for (int x = 0; x < n; x++) for (int y = 0; y < n; y++) cin >> grid[x][y];
    for (int x = 0; x < q; x++)
    {
        cin >> str1;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == str1[0])
                {
                    vector <vector <bool> > visited(n + 1, vector <bool>(n + 1, false));
                    visited[i][j] = true;
                    find_all(i, j, str1, 1, grid, flag, visited);
                }
                if (flag) break;
            }
            if (flag) break;
        }
        if (flag) cout << "good puzzle!\n";
        else cout << "bad puzzle!\n";
    }
}
