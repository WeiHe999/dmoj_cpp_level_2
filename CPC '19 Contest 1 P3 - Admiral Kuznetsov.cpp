#include <bits/stdc++.h>
using namespace std;
const int MM = 1e6+2;
int p0[MM], p1[MM];
int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string str1, str2;
    cin >> n >> str1 >> str2;
    for(int i=1; i<=n; i++){
        p0[i] = p0[i-1] + (str1[i-1] == '0');
        p1[i] = p1[i-1] + (str2[i-1] == '1');
    }
    vector <int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (str1[i - 1] == str2[i - 1]) dp[i] = min(dp[i], dp[i - 1]);
        else if (str1[i - 1] == '0' && str2[i - 1] == '1') dp[i] = min(dp[i - 1] + 1, dp[i]);
 
        for(int j=i+2; j<=min(n, i+4); j++){
            int op = j == i+4? 3 : 1;
            dp[j] = min(dp[j], dp[i-1] + (p0[j] - p0[i-1]) + op + (p1[j] - p1[i-1])); //# of 0s in str1 from i to j + (1 / 3 moves) + # of 1s in str2 from i to j
        }
    }
    if (dp[n] >= 1e9) cout << "-1\n";
    else cout << dp[n] << "\n";
}
