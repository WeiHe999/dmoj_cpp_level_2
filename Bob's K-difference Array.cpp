#include <bits/stdc++.h>
using namespace std;

long long n, k, s = 0;
vector <vector <long long> > dp((1 << 16), vector <long long>(17, -1));
vector <long long> vec1(17);

long long rec(long long mask, long long cur)
{
    if (mask == (1 << n) - 1) return 1;
    if (dp[mask][cur] != -1) return dp[mask][cur];
    long long s = 0;
    for (long long i = 1; i <= n; i++)
    {
        if ((mask & (1 << (i - 1))) || abs(vec1[i] - vec1[cur]) <= k) continue;
        s += rec(mask | (1 << (i - 1)), i);
    }
    return dp[mask][cur] = s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k;
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    for (long long i = 1; i <= n; i++) s += rec((1 << (i - 1)), i);
    cout << s << "\n";
}
