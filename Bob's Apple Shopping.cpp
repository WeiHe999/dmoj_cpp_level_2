#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, s = 1e9;
    cin >> n >> m;
    vector <int> values(n + 1), weights(n + 1);
    for (int i = 1; i <= n; i++) cin >> weights[i] >> values[i];
    vector <int> memo(1e5 + 1, 1e9);
    memo[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= 1e5; j++)
        {
            if (memo[j] == 1e9) continue;
            if (j + weights[i] <= 1e5) memo[j + weights[i]] = min(memo[j] + values[i], memo[j + weights[i]]);
        }
    }
    for (int i = m; i <= 1e5; i++) s = min(memo[i], s);
    cout << s << "\n";
}
