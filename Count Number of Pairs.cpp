#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, s = 0;
    cin >> n >> m;
    vector <long long> vec1(n);
    for (long long x = 0; x < n; x++) cin >> vec1[x];
    sort(vec1.begin(), vec1.end());
    for (long long y = 0; y < n - 1; y++)
    {
        long long ind = (upper_bound(vec1.begin(), vec1.end(), m - vec1[y]) - vec1.begin()) - 1;
        if (y < ind && m >= vec1[y] + vec1[ind])
        {
            s += ind - y;
        }
    }
    cout << s << "\n";
}
