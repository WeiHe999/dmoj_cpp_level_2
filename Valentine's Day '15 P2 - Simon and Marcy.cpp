#include <bits/stdc++.h>
using namespace std;

const int MM = 1e9;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int c, m, s = 0;
    cin >> c >> m;
    vector <int> weights(c + 1), values(c + 1);
    for (int x = 1; x <= c; x++) cin >> values[x] >> weights[x];
    vector <int> memo(m + 1, -1);
    memo[0] = 0;
    for (int j = 1; j <= c; j++)
    {
        vector <pair <int, int> > vec1;
        for (int i = 0; i <= m; i++)
        {
            if (memo[i] == -1) continue;
            if (i + weights[j] <= m) vec1.push_back({i + weights[j], max(memo[i] + values[j], memo[i + weights[j]])});
        }
        for (auto x : vec1) memo[x.first] = x.second;
    }
    for (auto x : memo) s = max(x, s);
    cout << s << "\n";
}
