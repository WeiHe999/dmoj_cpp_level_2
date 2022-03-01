#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y, g, s;
    string b, d, h, i, j;
    cin >> x;
    unordered_map <string, unordered_set <string> > m1, m2;
    for (int a = 0; a < x; a++)
    {
        cin >> b >> d;
        m1[b].insert(d);
    }
    cin >> y;
    for (int c = 0; c < y; c++)
    {
        cin >> b >> d;
        m2[b].insert(d);
    }
    // for (auto e : m1)
    // {
    //     cout << e.first << " " << e.second << endl;
    // }
    // cout << endl;
    // for (auto e : m2)
    // {
    //     cout << e.first << " " << e.second << endl;
    // }
    // cout << endl;
    s = x;
    cin >> g;
    for (int e = 0; e < g; e++)
    {
        cin >> h >> i >> j;
        if (m1[h].count(i) || m1[i].count(h)) s--;
        if (m1[h].count(j) || m1[j].count(h)) s--;
        if (m1[j].count(i) || m1[i].count(j)) s--;
        if (m2[h].count(i) || m2[i].count(h)) s++;
        if (m2[h].count(j) || m2[j].count(h)) s++;
        if (m2[j].count(i) || m2[i].count(j)) s++;
    }
    cout << s << endl;
}
