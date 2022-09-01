#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, d, c, y, a;
    cin >> n >> d >> c >> y;
    unordered_map <long long, long long> m1, memo;
    vector<long long> v2;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        v2.push_back(a);
        memo[x + 1] = LLONG_MAX;
    }
    memo[1] = 0;
    
    for (long long i = 0; i < n; i++)
    {
        m1[i+1] = -1;
        for (long long j = i+1; j <= min(i+d, n-1); j++)
        {
            if (v2[j] > v2[i])
            {
                m1[i+1] = j+1;
                break;
            }
        }
    }
    
    for (long long x = 1; x < n; x++)
    {
        if (x + 1 <= n) memo[x + 1] = min(memo[x] + y, memo[x + 1]);
        if (x + 2 <= n) memo[x + 2] = min(memo[x] + y, memo[x + 2]);
        if (m1[x] != -1) memo[m1[x]] = min(memo[x] + c, memo[m1[x]]);
    }
    cout << memo[n] << "\n";

   
}
