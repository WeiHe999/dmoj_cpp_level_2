#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, a, b;
    cin >> n >> m;
    vector <long long> start(m + 1), end(m + 1), freq_start(2 * m + 1), freq_end(2 * m + 1);
    for (long long x = 0; x < n; x++)
    {
        cin >> a >> b;
        start[a]++;
        end[b]++;
    }
    for (long long x = 0; x < start.size(); x++)
    {
        for (long long y = 0; y < start.size(); y++)
        {
            freq_start[x + y] += start[x] * start[y] ;
        }
    }
    for (long long x = 0; x < end.size(); x++)
    {
        for (long long y = 0; y < end.size(); y++)
        {
            freq_end[x + y] += end[x] * end[y] ;
        }
    }
    long long s = 0;
    for (long long x = 0; x < 2 * m + 1; x++)
    {
        s += freq_start[x];
        cout << s << "\n";
        s -= freq_end[x];
    }
}
