#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, u, r, s = 0;
    cin >> m >> u >> r;
    vector <int> values(r + 1), weights(r + 1), food(r + 1);
    for (int i = 1; i <= r; i++) cin >> values[i] >> weights[i] >> food[i];
    vector <vector <int> > memo(m + 1, vector <int>(u + 1));
    for (int i = 1; i <= r; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = u; k >= 0; k--)
            {
                if (j + weights[i] <= m && k + food[i] <= u)
                {
                    memo[j + weights[i]][k + food[i]] = max(memo[j][k] + values[i], memo[j + weights[i]][k + food[i]]);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) for (int j = 1; j <= u; j++) s = max(memo[i][j], s);
    cout << s << "\n";
}
