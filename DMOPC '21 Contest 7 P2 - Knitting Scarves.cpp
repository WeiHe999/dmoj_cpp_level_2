#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, l, r, k;
    cin >> n >> q;
    unordered_map <int, pair <int, int> > m1;
    for (int y = 0; y <= n; y++) m1[y] = {y - 1, y + 1};
    for (int x = 0; x < q; x++)
    {
        cin >> l >> r >> k;
        m1[m1[l].first].second = m1[r].second;
        m1[m1[r].second].first = m1[l].first;
        m1[l].first = k;
        m1[r].second = m1[k].second;
        m1[m1[k].second].first = r;
        m1[k].second = l;
    }
    int a = 0;
    while (true)
    {
        a = m1[a].second;
        if (m1[a].second == n + 1)
        {
            cout << a << endl;
            break;
        }
        cout << a << " ";
    }
}
