#include <bits/stdc++.h>
using namespace std;



int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    long long n = str1.size();
    vector<long long> dp(n+1, 0);
    for (long long i=1; i<=n; i++)
    {
        if (str1[i-1]=='l')
        {
            dp[i] = 1;
            for (long long j=i+1; j<=n; j++)
            {
                if (str1[j-1]=='o') dp[j] = dp[j] + dp[i];
            }
        }


        if (str1[i-1]=='o')
        {
            for (long long j=i+1; j<=n; j++)
            {
                if (str1[j-1]=='v') dp[j] = dp[j] + dp[i];
            }
        }
        

        if (str1[i-1]=='v')
        {
            for (long long j=i+1; j<=n; j++)
            {
                if (str1[j-1]=='e') dp[j] = dp[j] + dp[i];
            }
        }          

    }     
    
    
    //prlong long(dp);
    long long ans = 0;
    for (long long i=1; i<=n; i++)
    {
        if (str1[i-1]=='e') ans += dp[i];
    }
    
    cout << ans << endl;
    
}
