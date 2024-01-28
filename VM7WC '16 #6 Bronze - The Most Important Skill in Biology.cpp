#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, s = 0;
    cin >> n;
    vector <pair <int, int> > vec1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        vec1[i] = {a, b};
    }
    s += vec1[0].first * vec1[n - 1].second - vec1[0].second * vec1[n - 1].first;
    for (int i = n - 1; i > 0; i--) s += vec1[i].first * vec1[i - 1].second - vec1[i].second * vec1[i - 1].first;
    cout << ceil(abs(s) / 2.0) << "\n";
}
