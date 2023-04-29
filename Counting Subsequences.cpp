#include <bits/stdc++.h>
using namespace std;
const int m = 10007;

int main()
{
    string str1;
    cin >> str1;
    vector <int> last_occurrence(256, -1), dp(str1.size() + 1);
    dp[0] = 1;
    for (int i = 1; i <= str1.size(); i++)
    {
        dp[i] = (2 * dp[i - 1] + m) % m;
        if (last_occurrence[str1[i - 1]] != -1) dp[i] -= dp[last_occurrence[str1[i - 1]]];
        last_occurrence[str1[i - 1]] = i - 1;
    }
    cout << (dp[str1.size()] - 1 +m) % m << "\n";
}
