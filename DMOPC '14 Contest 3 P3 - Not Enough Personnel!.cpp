#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, b, q, c, d;
    string a;
    cin >> n;
    vector <pair <int, string> > vec1;
    vector <int> vec2;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec1.push_back({b, a});
        vec2.emplace_back(b);
    }
    stable_sort(vec1.begin(), vec1.end(), [](pair <int, string> a, pair <int, string> b){return a.first < b.first;});
    sort(vec2.begin(), vec2.end());
    cin >> q;
    for (int y = 0; y < q; y++)
    {
        cin >> c >> d;
        int f = lower_bound(vec2.begin(), vec2.end(), c) - vec2.begin();
        pair <int, string> e = vec1[f];
        if (f != vec2.size() && e.first <= c + d) cout << e.second << endl;
        else cout << "No suitable teacher!" << endl;
    }
}
