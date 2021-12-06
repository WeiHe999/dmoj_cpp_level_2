#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a, b, ans = 0;
    vector <int> p1, p2;
    cin >> n;
    set <vector <int> > s;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        s.insert({a, b});
    }
    for (auto i : s)
    {
        for (auto j : s)
        {
            p1 = {i[0], j[1]};
            p2 = {j[0], i[1]};
            if (s.count(p1) && s.count(p2)) if (abs(j[0] - i[0]) * abs(j[1] - i[1]) > ans) ans = abs(j[0] - i[0]) * abs(j[1] - i[1]);
        }
    }
    cout << ans << endl;
}
