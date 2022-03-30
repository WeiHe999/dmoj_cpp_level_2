#include <bits/stdc++.h>
using namespace std;

int find_dist(char a, char b)
{
    int min_c = min(a, b);
    int max_c = max(a, b);
    return min(max_c - min_c, min_c + 26 - max_c);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k;
    string str1;
    cin >> k >> str1;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    for (auto a : alpha)
    {
        for (auto b : alpha)
        {
            for (auto c : alpha)
            {
                for (auto d : alpha)
                {
                    if (find_dist(a, str1[0]) + find_dist(b, str1[1]) + find_dist(c, str1[2]) + find_dist(d, str1[3]) <= k) cout << a << b << c << d << endl;
                }
            }
        }
    }
}
