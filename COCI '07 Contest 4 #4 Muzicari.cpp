#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, n;
    cin >> t >> n;
    vector <long long> weights(n + 1);
    for (long long i = 1; i <= n; i++) cin >> weights[i];
    vector <vector <long long> > memo(t + 1);
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = t; j >= 0; j--)
        {
            if ((memo[j].size() > 0 || j == 0) && j + weights[i] <= t)
            {
                memo[j + weights[i]] = memo[j];
                memo[j + weights[i]].emplace_back(i);
            }
        }
    }
    unordered_set <int> grp1, grp2;
    for (long long i = t; i >= 1; i--)
    {
        if (memo[i].size() > 0)
        {
            for (auto x : memo[i]) grp1.insert(x);
            for (long long j = 1; j <= n; j++) if (!grp1.count(j)) grp2.insert(j);
            break;
        }
    }
    vector <long long> output(n + 1);
    long long s = 0;
    for (auto x : grp1)
    {
        output[x] = s;
        s += weights[x];
    }
    s = 0;
    for (auto x : grp2)
    {
        output[x] = s;
        s += weights[x];
    }
    for (long long x = 1; x <= n; x++) cout << output[x] << " ";
    cout << "\n";
}
