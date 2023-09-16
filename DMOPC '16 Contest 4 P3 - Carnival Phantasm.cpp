#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s, q, a, b;
    char c;
    cin >> n >> s;
    unordered_map <int, int> m1;
    unordered_map <int, unordered_set <int> > m2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        m1[i] = a;
    }
    unordered_map <int, set <pair <int, int> > > m3;
    for (int i = 1; i <= s; i++)
    {
        cin >> a >> b;
        m2[a].insert(b);
        m3[b].insert({m1[a], a});
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 'A')
        {
            cin >> a >> b;
            m2[a].insert(b);
            m3[b].insert({m1[a], a});
        }
        else if (c == 'S')
        {
            cin >> a >> b;
            if (m2.count(a)) m2[a].erase(b);
            if (m3[b].count({m1[a], a})) m3[b].erase({m1[a], a});
        }
        else if (c == 'E')
        {
            cin >> a >> b;
            if (m2.count(a)) //m2: {stand_id: {flavor-1, flavor-2}}
            {
                for (auto x: m2[a]) // flavors, x is flavor
                {
                    m3[x].erase({m1[a], a}); //m3 " {flavor_1: {{dist_1, stand_1}}"
                    // cout << "erase: (" << m1[a] << ", " << a << ")\n"; // x is flavor
                }
                m2.erase(a);
            }
            m1[a] = b;
        }
        else
        {
            cin >> a;
            if (m3[a].size() >= 1) cout << (m3[a].begin())->second << "\n";
            else cout << "-1\n";
        }
    }
}
