#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s;
    int q, x, y, z, e;
    cin >> s >> q;
    vector <int> vec_0, vec_1, vec, vec2;
    for (int a = 0; a < s.size(); a++)
    {
        if (s[a] == '0')
        {
            vec_0.emplace_back(1);
            vec_1.emplace_back(0);
        }
        else
        {
            vec_0.emplace_back(0);
            vec_1.emplace_back(1);
        }
    }
    for (int b = 0; b < vec_0.size(); b++)
    {
        if (b == 0) vec.emplace_back(vec_0[b]);
        else vec.emplace_back(vec[b - 1] + vec_0[b]);
    }
    for (int c = 0; c < vec_1.size(); c++)
    {
        if (c == 0) vec2.emplace_back(vec_1[c]);
        else vec2.emplace_back(vec2[c - 1] + vec_1[c]);
    }
    for (int d = 0; d < q; d++)
    {
        cin >> x >> y >> z;
        if (z == 0)
        {
            if (x - 2 >= 0) e = lower_bound(vec.begin(), vec.end(), vec[x - 2] + y) - vec.begin();
            else e = lower_bound(vec.begin(), vec.end(), y) - vec.begin();
            if (e >= vec.size()) cout << -1 << endl;
            else cout << e + 1 << endl;
        }
        else
        {
            if (x - 2 >= 0) e = lower_bound(vec2.begin(), vec2.end(), vec2[x - 2] + y) - vec2.begin();
            else e = lower_bound(vec2.begin(), vec2.end(), y) - vec2.begin();
            if (e >= vec2.size()) cout << -1 << endl;
            else cout << e + 1 << endl;
        }
    }
}
