#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long r, c;
    cin >> r >> c;
    vector <vector <char> > grid(r + 1, vector <char>(c + 1, '.'));
    vector <vector <long long> > memo(r + 1, vector <long long>(c + 1));
    for (long long i = 1; i <= r; i++) for (long long j = 1; j <= c; j++) cin >> grid[i][j];
    memo[1][1] = 1;
    for (long long i = 1; i <= r; i++)
    {
        for (long long j = 1; j <= c; j++)
        {
            if ((i == 1 && j == 1) || grid[i][j] == '#') continue;
            memo[i][j] = (memo[i - 1][j] + memo[i][j - 1])  % 1000000007;
        }
    }
    cout << memo[r][c] << "\n";
}
