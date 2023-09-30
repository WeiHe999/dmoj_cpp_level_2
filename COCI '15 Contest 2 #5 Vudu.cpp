#include <bits/stdc++.h>
using namespace std;

long long MM = 1 << 20;

void update(long long ind, vector <long long> &bit, int n)
{
    for (long long i = ind; i < MM; i += (i & -i)) bit[i]++;
}

long long query(long long ind, vector <long long> &bit)
{
    long long s = 0;
    for (long long i = ind; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int main()
{
    long long n, p;
    cin >> n;
    vector <double> vec1(n);
    vector <long long> bit(MM);
    for (long long i = 0; i < n; i++) cin >> vec1[i];
    cin >> p;
    for (long long i = 0; i < n; i++)
    {
        vec1[i] -= p;
        if (i > 0) vec1[i] += vec1[i - 1];
    }
    vector <pair <double, long long> > vec2;
    for (long long i = 0; i < n; i++) vec2.push_back({vec1[i], i});
    vec2.push_back({0, -1});
    sort(vec2.begin(), vec2.end(), [](pair <double, long long> a, pair <double, long long> b)
    {if (a.first != b.first) return a.first < b.first; return a.second < b.second;});
    long long ind = 0, ans = 0;
    for (long long i = 0; i < vec2.size(); i++)
    {
        while (ind < i && (vec2[i].first - vec2[ind].first) >= 0)
        {
            update(vec2[ind].second + 10, bit, n);
            ind++;
        }
        ans += query(vec2[i].second + 10, bit);
    }
    cout << ans << "\n";
}
