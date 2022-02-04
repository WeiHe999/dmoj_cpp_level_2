#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, l, r;
    cin >> n >> q;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    for (int y = 0; y < q; y++)
    {
        cin >> l >> r;
        cout << (upper_bound(vec1.begin(), vec1.end(), r) - 1 - vec1.begin()) - (lower_bound(vec1.begin(), vec1.end(), l) - vec1.begin()) + 1 << endl;
    }
}
