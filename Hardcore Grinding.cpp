#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, ans = 0;
    cin >> n;
    map <pair <int, int>, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        m1[make_pair(a, b)]++;
    }
    auto x = m1.begin();
    bool flag = true;
    pair <int, int> c;
    while (!m1.empty())
    {
        if (flag)
        {
            c = (*m1.begin()).first;
            flag = false;
        }
        else 
        {
            if (m1[c] == 0) m1.erase(c);
            c = (*m1.begin()).first;
        }
        while (true)
        {
            m1[c]--;
            if (m1[c] == 0) m1.erase(c);
            auto it = m1.lower_bound(make_pair(c.second, INT_MIN));
            c = (*it).first;
            if (!m1.count(c))
            {
                ans++;
                break;
            }
        }
    }
    cout << ans << "\n";
}
