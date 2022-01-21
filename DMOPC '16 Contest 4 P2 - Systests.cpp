#include <bits/stdc++.h>
using namespace std;
template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long b, c, e, p, f, t, s = 0;
    cin >> b;
    vector <vector <long long> > vec1;
    vector <long long> vec2;
    for (long long x = 0; x < b; x++)
    {
        cin >> c >> e >> p;
        vec1.push_back({c - 1, e - 1, p});
    }
    cin >> f;
    for (long long y = 0; y < f; y++)
    {
        cin >> t;
        vec2.emplace_back(t - 1);
    }
    sort(vec2.begin(), vec2.end());
    for (auto d : vec1)
    {
        if (lower_bound(vec2.begin(), vec2.end(), d[0]) == vec2.end() || vec2[lower_bound(vec2.begin(), vec2.end(), d[0]) - vec2.begin()] > d[1])
        {
            s += d[2];
        }
    }
    cout << s << endl;
}
