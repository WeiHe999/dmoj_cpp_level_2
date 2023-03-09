#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, d = 0, k = 0, o = 0, r = 0, s, tmp;
    string str1;
    cin >> n >> m >> str1;
    for (auto x : str1)
    {
        if (x == 'd') d++;
        else if (x == 'k') k++;
        else if (x == 'o') o++;
        else r++;
    }
    s = d * d + k * k + o * o + r * r + 7 * (min({k / 2, r, o / 2, d}));
    for (int a = 0; a <= m; a++)
    {
        for (int b = 0; b <= m; b++)
        {
            for (int c = 0; c <= m; c++)
            {
                for (int e = 0; e <= m; e++)
                {
                    if (a + b + c + e <= m)
                    {
                        s = max((a + d) * (a + d) + (b + k) * (b + k) + (c + o) * (c + o) + (e + r) * (e + r) + 7 * min({(b + k) / 2, e + r,
                        (c + o) / 2, a + d}), s);
                    }
                }
            }
        }
    }
    cout << s << "\n";
}
