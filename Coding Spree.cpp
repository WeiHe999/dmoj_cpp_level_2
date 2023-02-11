#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, a, b;
    cin >> n >> t;
    vector <pair <int, int> > vec1(n + 1);
    for (int x = 1; x <= n; x++)
    {
        cin >> a >> b;
        vec1[x] = {a, b};
    }
    vector <vector <int> > memo(n + 1, vector <int>(t + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= t; j++)
        {
            if (j < vec1[i].second) memo[i][j] = memo[i - 1][j];
            else memo[i][j] = max(memo[i - 1][j - vec1[i].second] + vec1[i].first, memo[i - 1][j]);
        }
    }
    cout << memo[n][t] << "\n";
}
