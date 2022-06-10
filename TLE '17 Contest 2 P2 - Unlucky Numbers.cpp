#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k, a, n, b;
    cin >> k;
    vector <int> vec1(k);
    for (int x = 0; x < k; x++) cin >> vec1[x];
    sort(vec1.begin(), vec1.end());
    cin >> n;
    for (int y = 0; y < n; y++)
    {
        cin >> b;
        cout << b - (upper_bound(vec1.begin(), vec1.end(), b) - vec1.begin()) << "\n";
    }
}
