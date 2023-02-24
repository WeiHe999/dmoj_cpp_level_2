#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> french(n + 1), english(n + 1);
    vector <vector <int> > memo(n + 1, vector <int>(4));
    for (int x = 1; x <= n; x++) cin >> french[x];
    for (int x = 1; x <= n; x++) cin >> english[x];
    for (int x = 1; x <= n; x++)
    {
        memo[x][1] = max(max(memo[x - 1][1], memo[x - 1][2]), memo[x - 1][3]) + english[x];
        memo[x][2] = memo[x - 1][1] + french[x];
        memo[x][3] = memo[x - 1][2] + french[x];
    }
    cout << max(max(memo[n][1], memo[n][2]), memo[n][3]) << "\n";
}
