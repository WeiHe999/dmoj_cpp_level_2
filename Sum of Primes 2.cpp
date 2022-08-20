#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1(100001), psa = {0};
    for (int x = 2; x < 100001; x++)
    {
        if (vec1[x] == 0)
        {
            for (int y = 2 * x; y < 100001; y += x)
            {
                vec1[y]++;
            }
        }
    }
    for (int x = 2; x < vec1.size(); x++)
    {
        if (vec1[x] == 0) psa.emplace_back(psa.back() + x);
        else psa.emplace_back(psa.back());
    }
    int q, a, b;
    cin >> q;
    for (int x = 0; x < q; x++)
    {
        cin >> a >> b;
        cout << psa[b - 1] - psa[a - 2] << "\n";
    }
}
