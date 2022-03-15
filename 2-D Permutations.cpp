#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, q, a;
    cin >> n >> m >> q;
    vector <vector <int> > grid(n, vector <int>(m));
    vector <int> da(n * m + 1), psa = {0};
    for (int x = 1; x <= grid.size(); x++)
    {
        for (int y = 1; y <= grid[0].size(); y++)
        {
            da[x * y - 1]++;
            da[(n * m) - ((n - x + 1) * (m - y + 1) - 1)]--;
        }
    }
    for (int z = 0; z < da.size() - 1; z++)
    {
        psa.emplace_back(psa[z] + da[z]);
    }
    for (int b = 0; b < q; b++)
    {
        cin >> a;
        cout << psa[a] << endl;
    }
}
