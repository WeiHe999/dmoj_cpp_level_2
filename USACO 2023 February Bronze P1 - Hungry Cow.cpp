#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, t, a, b;
    cin >> n >> t;
    unordered_map <long long, long long> m1;
    long long missing = 0, cur_day = 1, cur_hay = 0, left;
    for (long long i = 0; i < n; i++)
    {
        cin >> a >> b;
        left = cur_hay - (a - cur_day);
        if (left < 0) 
        {
            missing -= left;
            left = 0;
        }
        cur_hay = left;
        if (a > t) break;
        m1[a] = b;
        cur_day = a;
        cur_hay += b;
    }
    a = t + 1;
    if (a - cur_day - cur_hay > 0) missing += a - cur_day - cur_hay;
    cout << t - missing << "\n";
}
