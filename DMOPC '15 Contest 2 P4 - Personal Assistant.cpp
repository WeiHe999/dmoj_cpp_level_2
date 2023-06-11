#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, c;
    cin >> n;
    vector <long long> dp(n + 1), start(n), end(n), values(n);
    vector <vector <long long> > vec1(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> a >> b >> c;
        vec1[i] = {a + b, a, c};
    }
    sort(vec1.begin(), vec1.end());
    for (long long i = 0; i < n; i++)
    {
        start[i] = vec1[i][1];
        end[i] = vec1[i][0];
        values[i] = vec1[i][2];
    }
    for (long long i = 1; i <= n; i++) dp[i] = max(dp[(upper_bound(end.begin(), end.end(), start[i - 1]) - end.begin())] + values[i - 1], dp[i - 1]);
    cout << dp[n] << "\n";
}
