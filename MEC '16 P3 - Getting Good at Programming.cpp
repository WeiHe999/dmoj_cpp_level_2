#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, l, t1, x1, s = 1;
    cin >> n >> t;
    vector <pair <int, int> > vec1 = {{0, 0}};
    vector <int> memo(t + 1, -1), index(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> l;
        index[i] = s;
        s += l;
        int s1 = 0, s2 = 0;
        for (int j = 1; j <= l; j++)
        {
            cin >> t1 >> x1;
            s1 += t1;
            s2 += x1;
            vec1.push_back({s1, s2});
        }
    }
    index[n + 1] = s;
    memo[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = t; j >= 0; j--)
        {
            if (memo[j] == -1) continue;
            for (int k = index[i]; k < index[i + 1]; k++)
            {
                if (j + vec1[k].first <= t) memo[j + vec1[k].first] = max(memo[j] + vec1[k].second, memo[j + vec1[k].first]);
            }
        }
    }
    s = 0;
    for (int i = 1; i <= t; i++) s = max(memo[i], s);
    cout << s << "\n";
}
