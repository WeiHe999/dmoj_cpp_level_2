#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, s = 0;
    cin >> n;
    vector <long long> vec1, vec2;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    if (n % 2 == 0)
    {
        for (long long b = 0; b < n / 2 - 1; b++) s -= 2 * vec1[b];
        for (long long c = n / 2 + 1; c < n; c++) s += 2 * vec1[c];
        s -= vec1[n / 2 - 1];
        s += vec1[n / 2];
    }
    else
    {
        for (long long b = 0; b < ceil(n / 2) - 1; b++) s -= 2 * vec1[b];
        for (long long c = ceil(n / 2) + 2; c < n; c++) s += 2 * vec1[c];
        vec2.emplace_back(vec1[ceil(n / 2) - 1]);
        vec2.emplace_back(vec1[ceil(n / 2)]);
        vec2.emplace_back(vec1[ceil(n / 2) + 1]);
        vector <long long> dist;
        for (long long d = 0; d < 3; d++)
        {
            for (long long e = d + 1; e < 3; e++)
            {
                dist.emplace_back(abs(vec2[d] - vec2[e]));
            }
        }
        sort(dist.begin(), dist.end());
        s += dist[2] + dist[1];
    }
    cout << s << endl;
}
