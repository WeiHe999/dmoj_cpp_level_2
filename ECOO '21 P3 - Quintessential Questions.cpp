#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, a, b, c;
    cin >> n >> m >> k;
    vector <pair <int, int>> best(n + 1, {0, -1});
    for (int x = 0; x < k; x++)
    {
        cin >> a >> b >> c;
        if (c > best[b].first)
        {
            best[b] = {c, a};
        }
    }
    for (int y = 1; y < best.size(); y++) cout << best[y].second << " ";
    cout << endl;
}
