#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, d, l, r;
    cin >> n >> d;
    vector <int> vec1(n + 1), dp(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    deque <pair <int, int> > q1;
    dp[1] = vec1[1];
    for (int i = 2; i <= n; i++)
    {
        l = max(i - d, 1), r = i - 1;
        while (!q1.empty() && q1.back().first > dp[r]) q1.pop_back();
        q1.push_back({dp[r], r});
        if (q1.front().second < l)  q1.pop_front();
        l++;
        dp[i] = q1.front().first + vec1[i];
    }
    cout << dp[n] << "\n";
}
