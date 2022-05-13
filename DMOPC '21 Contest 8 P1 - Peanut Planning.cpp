#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a;
    vector <int> s;
    map <int, int> m1;
    cin >> n >> m;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    s.emplace_back(m1.begin()->first);
    m1.begin()->second--;
    if (m1.begin()->second == 0) m1.erase(m1.begin()->first);
    while (m1.size() != 0)
    {
        auto it = m1.lower_bound(m - s.back());
        if (it == m1.end())
        {
            cout << -1 << endl;
            return 0;
        }
        s.emplace_back(it->first);
        it->second--;
        if (it->second == 0) m1.erase(it->first);
    }
    for (auto b : s) cout << b << " ";
    cout << endl;
}
