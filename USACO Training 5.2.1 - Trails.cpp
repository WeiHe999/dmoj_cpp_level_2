#include <bits/stdc++.h>
using namespace std;

vector <vector <char> > grid(121, vector <char>(121, '.'));
vector <vector <bool> > vis(121, vector <bool>(121, false));

int rec(pair <int, int> cur_node, char dir, int steps, int n)
{
    if (cur_node.first == 0 || cur_node.first > n || cur_node.second == 0 || cur_node.second > n ||
        grid[cur_node.first][cur_node.second] != '.' || vis[cur_node.first][cur_node.second]) return steps;
    vis[cur_node.first][cur_node.second] = true;
    int s, tmp1, tmp2;
    if (dir == 'u')
    {
        if (cur_node.first > 1 && grid[cur_node.first - 1][cur_node.second] == '.')
        {
            s = rec({cur_node.first - 1, cur_node.second}, dir, steps + 1, n);
        }
        else
        {
            s = max(rec({cur_node.first, cur_node.second - 1}, 'l', steps + 1, n), rec({cur_node.first, cur_node.second + 1}, 'r', steps + 1, n));
        }
    }
    else if (dir == 'd')
    {
        if (cur_node.first < n && grid[cur_node.first + 1][cur_node.second] == '.')
        {
            s = rec({cur_node.first + 1, cur_node.second}, dir, steps + 1, n);
        }
        else
        {
            s = max(rec({cur_node.first, cur_node.second - 1}, 'l', steps + 1, n), rec({cur_node.first, cur_node.second + 1}, 'r', steps + 1, n));
        }
    }
    else if (dir == 'l')
    {
        if (cur_node.second > 1 && grid[cur_node.first][cur_node.second - 1] == '.')
        {
            s = rec({cur_node.first, cur_node.second - 1}, dir, steps + 1, n);
        }
        else
        {
            s = max(rec({cur_node.first - 1, cur_node.second}, 'u', steps + 1, n), rec({cur_node.first + 1, cur_node.second}, 'd', steps + 1, n));
        }
    }
    else
    {
        if (cur_node.second < n && grid[cur_node.first][cur_node.second + 1] == '.')
        {
            s = rec({cur_node.first, cur_node.second + 1}, dir, steps + 1, n);
        }
        else
        {
            s = max(rec({cur_node.first - 1, cur_node.second}, 'u', steps + 1, n), rec({cur_node.first + 1, cur_node.second}, 'd', steps + 1, n));
        }
    }
    vis[cur_node.first][cur_node.second] = false;
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, b;
    cin >> n >> b;
    string str1;
    for (int x = 0; x < b; x++)
    {
        cin >> str1;
        grid[stoi(str1.substr(1))][str1[0] - 'A' + 1] = '#';
    }
    cout << max(rec({1, 1}, 'd', 0, n), rec({1, 1}, 'r', 0, n)) << "\n";
}
