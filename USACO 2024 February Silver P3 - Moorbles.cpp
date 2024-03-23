#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        int n, m, k, a;
        cin >> n >> m >> k;
        vector <vector <int> > vec1;
        for (int i = 1; i <= m; i++)
        {
            vector <int> tmp(2, INT_MAX);
            for (int j = 0; j < k; j++)
            {
                cin >> a;
                tmp[a & 1] = min(tmp[a & 1], a);
                tmp[(a & 1) ^ 1] = min(tmp[(a & 1) ^ 1], -a);
            }
            vec1.push_back(tmp);
        }
        vector <int> vec2(m + 1);
        for (int i = m - 1; i >= 0; i--) vec2[i] = min(0ll, *max_element(vec1[i].begin(), vec1[i].end()) + vec2[i + 1]);
        if (n + vec2[0] <= 0)
        {
            cout << "-1\n";
            continue;
        }
        vector <int> ans;
        for (int i = 0; i < m; i++)
        {
            int p;
            if (n + vec1[i][0] + vec2[i + 1] <= 0) p = 1;
            else p = 0;
            ans.emplace_back(p);
            n += vec1[i][p];
        }
        for (auto x : ans)
        {
            if (x == 0) cout << "Even ";
            else cout << "Odd ";
        }
        cout << "\n";
    }
}
