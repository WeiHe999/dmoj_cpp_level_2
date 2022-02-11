#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    unordered_map <int, int> m1, m2;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    for (auto b : m1)
    {
        for (auto c : m1)
        {
            if (b == c)
            {
                m2[2 * b.first] += (b.second / 2) * 2;
            }
            else
            {
                m2[b.first + c.first] += min(b.second, c.second);
            }
        }
    }
    int max_num = 0, max_val = INT_MIN;
    for (auto d : m2)
    {
        if ((d.second / 2) == max_val) max_num++;
        if ((d.second / 2) > max_val)
        {
            max_val = (d.second / 2);
            max_num = 1;
        }
    }
    cout << max_val << " " << max_num << endl;
}
