#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (long long x = 0; x < 10; x++)
    {
        long long r, t;
        string str1, c;
        char b;
        cin >> r >> t >> str1;
        unordered_map <char, string> m1;
        unordered_map <char, long long> m2;
        for (auto e : str1) m2[e]++;
        char first = str1[0], last = str1.back();
        for (long long y = 0; y < r; y++)
        {
            cin >> b >> c;
            m1[b] = c;
        }
        for (long long z = 0; z < t; z++)
        {
            first = m1[first][0];
            last = m1[last].back();
            unordered_map <char, long long> m3;
            for (auto d : m2)
            {
                long long a1 = m2[d.first];
                for (auto f : m1[d.first])
                {
                    m3[f] += a1;
                }
            }
            m2 = m3;
        }
        long long sum = 0;
        for (auto g : m2)
        {
            sum += g.second;
        }
        cout << first << last << " " << sum << endl;
    }
}
