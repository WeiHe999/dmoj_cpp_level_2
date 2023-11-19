#include <bits/stdc++.h>
using namespace std;

unordered_map <long long, long long> dp;

long long rec(long long n, unordered_map <long long, long long> &dp)
{
    if (n == 1 || n == 2) return 1;
    if (dp.count(n)) return dp[n];
    long long s = 0, x = n;
    while (x >= 2)
    {
        int w = n / x, y = n / (w + 1);
        s += (long long)(x - y) * rec(w, dp);
        x = y;
    }
    return dp[n] = s;
}

int main()
{
    long long n;
    cin >> n;
    cout << rec(n, dp) << "\n";
}
