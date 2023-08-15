#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k;
    cin >> n >> k;
    vector <long long> vec1(n + 2), vec2;
    vector <pair <long long, long long> > dp(n + 2);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    dp[1] = {vec1[1], 0};
    deque <pair <long long, long long> > q1;
    q1.push_back({0, 0});
    for (long long i = 2; i <= n + 1; i++)
    {
        long long l = max(0ll, i - k), r = i - 1;
        while (!q1.empty() && q1.back().first >= dp[r].first) q1.pop_back();
        q1.push_back({dp[r].first, r});
        if (q1.front().second < l) q1.pop_front();
        dp[i] = {q1.front().first + vec1[i], q1.front().second};
    }
    cout << dp[n + 1].first << "\n";
    long long c = dp[n + 1].second;
    while (c != 0)
    {
        vec2.emplace_back(c);
        c = dp[c].second;
    }
    for (long long x = vec2.size() - 1; x >= 0; x--) cout << vec2[x] << " ";
    cout << "\n";
}
