#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    vector <vector <long long> > memo(n + 1, vector <long long>(n + 1));
    vector <long long> vec1(n + 1), psa = {0};
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        psa.emplace_back(psa.back() + vec1[i]);
    }
    for (long long k = 0; k <= n - 1; k++)
    {
        for (long long i = 1; i <= n - k; i++)
        {
            long long j = i + k;
            if (i == j) memo[i][j] = vec1[i];
            else if (i == j - 1 && vec1[i] == vec1[j]) memo[i][j] = 2 * vec1[i];
            else if (i == j - 1) memo[i][j] = max(vec1[i], vec1[j]);
            else
            {
                memo[i][j] = max(memo[i + 1][j], memo[i][j - 1]);
                long long l = i + 1, r = j;
                while (l <= r)
                {
                    if (memo[i][l - 1] < memo[r][j]) l++;
                    else if (memo[i][l - 1] > memo[r][j]) r--;
                    else if (memo[i][l - 1] == psa[l - 1] - psa[i - 1] && memo[l][r - 1] == psa[r - 1] - psa[l - 1] &&
                    memo[r][j] == psa[j] - psa[r - 1])
                    {
                        memo[i][j] = max(memo[i][l - 1] + memo[l][r - 1] + memo[r][j], memo[i][j]);
                        l++;
                        r--;
                    }
                    else
                    {
                        l++;
                        r--;
                    }
                }
            }
        }
    }
    cout << memo[1][n] << "\n";
}
