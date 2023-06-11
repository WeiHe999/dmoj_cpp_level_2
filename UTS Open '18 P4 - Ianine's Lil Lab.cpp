#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, b, ans = 0;
    cin >> n;
    unordered_map <long long, vector <pair <long long, long long> > > m1;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a >> b;
        m1[a + b].push_back({a, b});
    }
    for (auto x : m1)
    {
        vector <pair <long long, long long> > vec1 = x.second;
        sort(vec1.begin(), vec1.end());
        vector <long long> psa1(vec1.size()), psa2(vec1.size());
        for (long long i = 0; i < vec1.size(); i++)
        {
            if (i == 0) psa1[i] = vec1[i].second;
            else psa1[i] = psa1[i - 1] + vec1[i].second;
        }
        for (long long i = vec1.size() - 1; i >= 0; i--)
        {
            if (i == vec1.size() - 1) psa2[i] = vec1[i].first;
            else psa2[i] = psa2[i + 1] + vec1[i].first;
        }
        long long s = 0;
        for (long long i = 0; i < vec1.size() - 1; i++) s = max(min(psa1[i], psa2[i + 1]), s);
        ans = max(s, ans);
    }
    cout << ans << "\n";
}
