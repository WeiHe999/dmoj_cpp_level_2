#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, a, s = 0;
    cin >> m >> n;
    if (n <= m)
    {
        cout << 0 << "\n";
        return 0;
    }
    vector <int> vec1, dist;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    for (int b = 1; b < vec1.size(); b++) dist.emplace_back(vec1[b] - vec1[b - 1]);
    sort(dist.rbegin(), dist.rend());
    for (int y = m - 1; y < dist.size(); y++) s += dist[y];
    cout << s << "\n";
}
