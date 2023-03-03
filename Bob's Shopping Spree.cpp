#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, k, p, s, q, t, d, a, ans = 0;
    cin >> n >> m >> k;
    vector <vector <long long> > vec1 = {{0, 0, 0}};
    for (long long i = 1; i <= n; i++)
    {
        cin >> p >> s;
        vec1.push_back({p, s, 1});
    }
    for (long long i = 1; i <= m; i++)
    {
        cin >> q >> t >> d >> a;
        long long tmp = a, power = 0;
        while (tmp > 0)
        {
            long long b = pow(2, power);
            vec1.push_back({d * min(b, tmp), q * vec1[t][1] * min(b, tmp), 0});
            tmp -= b;
            power++;
        }
    }
    vector <long long> memo(k + 1, -1);
    memo[0] = 0;
    for (long long i = 1; i < vec1.size(); i++)
    {
        if (vec1[i][2])
        {
            for (long long j = 0; j <= k; j++)
            {
                if (memo[j] == -1) continue;
                if (j + vec1[i][0] <= k) memo[j + vec1[i][0]] = max(memo[j] + vec1[i][1], memo[j + vec1[i][0]]);
            }
        }
        else
        {
            for (long long j = k; j >= 0; j--)
            {
                if (memo[j] == -1) continue;
                if (j + vec1[i][0] <= k) memo[j + vec1[i][0]] = max(memo[j] + vec1[i][1], memo[j + vec1[i][0]]);
            }
        }
    }
    for (long long i = 1; i <= k; i++) ans = max(memo[i], ans);
    cout << ans << "\n";
}
