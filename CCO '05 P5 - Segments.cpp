#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1, 1), vec2(n + 1, 1);
    vector <vector <int> > dp(n + 1, vector <int>(2));
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i] >> vec2[i];
        dp[i][0] = vec2[i] - vec1[i] + min(dp[i - 1][0] + abs(vec1[i - 1] - vec2[i]), dp[i - 1][1] + abs(vec2[i - 1] - vec2[i])) + 1;
        dp[i][1] = vec2[i] - vec1[i] + min(dp[i - 1][0] + abs(vec1[i - 1] - vec1[i]), dp[i - 1][1] + abs(vec2[i - 1] - vec1[i])) + 1;
    }
    cout << min(dp[n][0] + n - vec1[n], dp[n][1] + n - vec2[n] - 1) << "\n";
}
