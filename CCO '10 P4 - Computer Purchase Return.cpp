#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, n, c, v, t1, b, s = -1;
    cin >> t >> n;
    unordered_map <int, vector <pair <int, int> > > m1;
    for (int i = 1; i <= n; i++)
    {
        cin >> c >> v >> t1;
        m1[t1].push_back({c, v});
    }
    cin >> b;
    if (m1.size() != t)
    {
        cout << "-1\n";
        return 0;
    }
    vector <vector <int> > memo(t + 1, vector <int>(b + 1, -1));
    memo[0][0] = 0;
    for (int i = 1; i <= t; i++)
    {
        for (auto x : m1[i])
        {
            for (int j = b; j >= 0; j--)
            {
                if (memo[i - 1][j] != -1 && j + x.first <= b) memo[i][j + x.first] = max(memo[i - 1][j] + x.second, memo[i][j + x.first]);
            }
        }
    }
    for (int j = 1; j <= b; j++) s = max(memo[t][j], s);
    cout << s << "\n";
}
