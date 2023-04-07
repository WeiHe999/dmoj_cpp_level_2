#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    vector <long long> vec1(n + 1), psa = {0};
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        psa.emplace_back(psa.back() + vec1[i]);
    }
    vector <vector <long long> > memo(n + 1, vector <long long>(n + 1, 1e18));
    for (int i = 1; i <= n; i++)
    {
        memo[i][i] = 0;
        if (i != n) memo[i][i + 1] = vec1[i] + vec1[i + 1];
    }
    for (int k = 2; k <= n - 1; k++)
    {
        for (int i = 1; i <= n - k; i++)
        {
            int j = i + k;
            for (int t = i; t < j; t++)
            {
                memo[i][j] = min(memo[i][t] + memo[t + 1][j] + psa[j] - psa[i - 1], memo[i][j]);
            }
        }
    }
    cout << memo[1][n] << "\n";
}
