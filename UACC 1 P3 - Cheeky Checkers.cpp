#include <bits/stdc++.h>
using namespace std;

vector <vector <int> > grid(9, vector <int>(9));
int s = 0;
vector <pair <int, int> > start_nodes;
char c;

void rec(pair <int, int> cur, int cur_step, set <pair <int, int> > &vis)
{
    vector <pair <int, int> > ops = {{2, 2}, {-2, 2}, {-2, -2}, {2, -2}};
    for (auto op: ops)
    {
        pair <int, int> p2 = {cur.first + op.first, cur.second + op.second};
        pair <int, int> p1 = {cur.first + op.first / 2, cur.second + op.second / 2};
        if (p2.first >= 1 && p2.first <= 8 && p2.first >= 1 && p2.second <= 8 && grid[p2.first][p2.second] == '.' && grid[p1.first][p1.second] == 'B' && !vis.count({p1.first, p1.second}))
        {
            s = max(s, cur_step);
            int new1 = cur_step + 1;
            set <pair <int, int> > tmp = vis;
            tmp.insert({p1.first, p1.second});
            rec(p2, new1, tmp);
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= 8; j++)
        {
            cin >> c;
            grid[i][j] = c;
            if (c == 'A') start_nodes.push_back({i, j});
        }
    }
    for (auto x : start_nodes)
    {
       int cur_step = 1;
       set <pair <int, int> > vis;
       rec(x, cur_step, vis);
    }
    cout << s << "\n";
}
