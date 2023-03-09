#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, a, b, c, ans = INT_MIN, cap = 0;
    cin >> n >> m;
    vector <pair <long long, long long> > vec1, vec2;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        long long tmp = a;
        for (long long d = 1; d <= a; d *= 2)
        {
            vec1.push_back({min(d, tmp) * b, min(d, tmp) * c});
            tmp -= d;
            if (tmp == 0) break;
        }
    }
    for (long long x = 1; x <= m; x++)
    {
        cin >> a >> b;
        vec2.push_back({a, b});
        cap = max(a, cap);
    }
    vector <long long> memo(cap + 1, -1);
    memo[0] = 0;
    for (long long i = 0; i < vec1.size(); i++)
    {
        for (long long j = cap; j >= 0; j--)
        {
            if (memo[j] == -1) continue;
            if (j + vec1[i].first <= cap) memo[j + vec1[i].first] = max(memo[j] + vec1[i].second, memo[j + vec1[i].first]);
        }
    }
    for (long long i = 0; i < vec2.size(); i++)
    {
        long long s = 0;
        for (long long j = 0; j <= vec2[i].first; j++) s = max(memo[j], s);
        ans = max(s - vec2[i].second, ans);
    }
    cout << ans << "\n";
}
