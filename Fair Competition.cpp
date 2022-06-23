#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, a;
    cin >> m >> n;
    vector <int> vec1;
    for (int x = 0; x < m; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.rbegin(), vec1.rend());
    int cur = vec1[n - 1], cur2 = vec1[n];
    if (cur != cur2)
    {
        cout << n << "\n";
    }
    else
    {
        int x = 0;
        while (vec1[x] > cur)
        {
            x++;
        }
        cout << x << "\n";
    }
}
