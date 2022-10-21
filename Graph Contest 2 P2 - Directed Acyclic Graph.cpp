#include <bits/stdc++.h>
using namespace std;

void floyd_warshall(vector <vector <int> > &reachable, int n)
{
    for (int mid = 1; mid <= n; mid++)
    {
        for (int beg = 1; beg <= n; beg++)
        {
            for (int end = 1; end <= n; end++)
            {
                reachable[beg][end] = min(reachable[beg][end], reachable[beg][mid] + reachable[mid][end]);
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <vector <int> > reachable(n + 1, vector <int>(n + 1, 1005));
    for (int x = 1; x <= n; x++)
    {
        for (int y = 1; y <= n; y++)
        {
            cin >> a;
            if (a == 1) reachable[x][y] = 1;
        }
    }
    floyd_warshall(reachable, n);
    bool flag = true;
    for (int x = 1; x <= n; x++)
    {
        if (reachable[x][x] < 1005)
        {
            flag = false;
            break;
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
