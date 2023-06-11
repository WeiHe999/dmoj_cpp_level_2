#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a, b;
    cin >> n >> k;
    vector <long long> dp(k + 1), start(k), end(k), values(k);
    vector <pair <long long, long long> > vec1(k);
    for (long long i = 0; i < k; i++)
    {
        cin >> a >> b;
        vec1[i] = {b, a};
    }
    sort(vec1.begin(), vec1.end());
    for (long long i = 0; i < k; i++)
    {
        start[i] = vec1[i].second;
        end[i] = vec1[i].first;
        values[i] = vec1[i].first - vec1[i].second + 1;
    }
    for (long long i = 1; i <= k; i++) dp[i] = max(dp[(lower_bound(end.begin(), end.end(), start[i - 1]) - end.begin())] + values[i - 1], dp[i - 1]);
    cout << n - dp[k] << "\n";
}
