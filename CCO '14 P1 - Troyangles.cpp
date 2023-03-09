#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <vector <long long> > grid(n + 1, vector <long long>(n + 2));
    char a;
    for (long long i = 0; i < n; i++)
    {
        grid[i][0] = 0;
        grid[i][n + 1] = 0;
        for (long long j = 1; j <= n; j++)
        {
            cin >> a;
            if (a == '#') grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
    for (long long i = n - 2; i >= 0; i--)
    {
        for (long long j = 1; j <= n; j++)
        {
            if (grid[i][j] == 1) grid[i][j] += min({grid[i + 1][j - 1], grid[i + 1][j], grid[i + 1][j + 1]});
        }
    }
    for (long long i = 0; i < n; i++) for (long long j = 1; j <= n; j++) s += grid[i][j];
    cout << s << "\n";
}
