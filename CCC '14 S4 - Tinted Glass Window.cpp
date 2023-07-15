#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, t, a, b, c, d, e, ind = 0, l = 0, s = 0;
    cin >> n >> t;
    vector <vector <long long> > s1;
    vector <long long> s2;
    set <long long> s3;
    for (long long i = 0; i < n; i++)
    {
        cin >> a >> b >> c >> d >> e;
        s1.push_back({a, b, d, e});
        s1.push_back({c, b, d, -e});
        s3.insert(b);
        s3.insert(d);
    }
    sort(s1.begin(), s1.end());
    for (auto x : s3) s2.emplace_back(x);
    vector <long long> vec1(s2.size() - 1);
    for (auto x : s1)
    {
        for (long long j = 0; j < s2.size() - 1; j++) if (vec1[j] >= t) s += (s2[j + 1] - s2[j]) * (x[0] - l);
        for (long long j = 0; j < s2.size() - 1; j++) if (x[1] <= s2[j] && x[2] >= s2[j + 1]) vec1[j] += x[3];
        l = x[0];
    }
    cout << s << "\n";
}
