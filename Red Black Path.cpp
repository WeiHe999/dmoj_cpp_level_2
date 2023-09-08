#include <bits/stdc++.h>
using namespace std;

long long r, c;
vector <vector <bool> > global_vis(401, vector <bool>(401, false));
vector <vector <char> > grid(401, vector <char>(401));

pair <long long, long long> dfs(long long i, long long j)
{
    global_vis[i][j] = true;
    vector <pair <long long, long long> > ops = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    long long s1 = 0, s2 = 0;
    if (grid[i][j] == '.') s1++;
    if (grid[i][j] == '#') s2++;
    for (auto x : ops)
    {
        if (i + x.first >= 1 && i + x.first <= r && j + x.second >= 1 && j + x.second <= c && grid[i + x.first][j + x.second] != grid[i][j] && 
        !global_vis[i + x.first][j + x.second])
        {
            pair <long long, long long> res = dfs(i + x.first, j + x.second);
            s1 += res.first;
            s2 += res.second;
        }
    }
    return {s1, s2};
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long s = 0;
    cin >> r >> c;
    for (long long i = 1; i <= r; i++) for (long long j = 1; j <= c; j++) cin >> grid[i][j];
    for (long long i = 1; i <= r; i++)
    {
        for (long long j = 1; j <= c; j++)
        {
            if (global_vis[i][j]) continue;
            pair <long long, long long> res = dfs(i, j);
            s += res.first * res.second;
        }
    }
    cout << s << "\n";
}
