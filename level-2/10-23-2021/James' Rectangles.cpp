#include <bits/stdc++.h>
using namespace std;

long long distance(long long x1, long long y1, long long x2, long long y2)
{
    return (long long) pow(x2 - x1, 2) +pow(y2 - y1, 2);
}

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long n, a, b, x1, x2, y1, y2, d, x_m, y_m, before, after, ans = 0;
    cin >> n;
    vector <vector <long long> > s1;
    map <vector <long long>, set <vector <long long> > > m1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a >> b;
        s1.push_back({a, b});
    }
    vector <vector <long long> > t;
    vector <long long> key, value, vs;
    for (int h = 0; h < s1.size(); h++)
    {
        for (int i = h + 1; i < s1.size(); i++)
        {
            x1 = s1[h][0]; x2 = s1[i][0]; y1 = s1[h][1]; y2 = s1[i][1];
            d = distance(x1, y1, x2, y2);
            t = {{x1, y1}, {x2, y2}};
            sort(t.begin(), t.end());
            key = {d, x1 + x2, y1 + y2};
            value = {t[0][0], t[0][1], t[1][0], t[1][1]};
            before = m1[key].size();
            m1[key].insert(value);
            after = m1[key].size();
            if (after > before) ans += before;
        }
    }
    cout << ans << endl;
}
