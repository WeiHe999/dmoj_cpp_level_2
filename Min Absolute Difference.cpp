#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, p1 = 0, p2 = 0, min_diff = INT_MAX;
    cin >> n >> m;
    vector <int> vec1, vec2;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int x = 0; x < m; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());
    while (p1 < vec1.size() && p2 < vec2.size())
    {
        min_diff = min(abs(vec2[p2] - vec1[p1]), min_diff);
        if (min_diff == 0) break;
        if (vec2[p2] > vec1[p1]) p1++;
        else p2++;
    }
    cout << min_diff << "\n";
}
