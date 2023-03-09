#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    vector <long long> weights(n + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> weights[i];
        s += weights[i];
    }
    vector <bool> memo(s + 1, false);
    memo[0] = true;
    for (long long i = 1; i <= n; i++)
    {
        for (long long j = s; j >= 0; j--)
        {
            if (memo[j] && j + weights[i] <= s) memo[j + weights[i]] = true;
        }
    }
    for (long long i = floor(s / 2.0); i >= 0; i--)
    {
        if (memo[i])
        {
            cout << abs(s - 2 * i) << "\n";
            break;
        }
    }
}
