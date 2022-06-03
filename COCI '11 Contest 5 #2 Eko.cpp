#include <bits/stdc++.h>
using namespace std;

int n, m, lo = 0, hi = 0;
vector <int> a(1000003);

bool check(int mid)
{
    long long s = 0;
    for (int x = 0; x < n; x++) if (a[x] - mid > 0) s += a[x] - mid;
    if (s < m) return true;
    return false;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    for(int x = 0; x < n; x++)
    {
        cin >> a[x];
        if (a[x] > hi) hi = a[x];
    }
    while (lo < hi)
    {
        int mid = ceil((lo + hi) / 2.0);
        if (check(mid)) hi = mid - 1;
        else lo = mid;
    }
    cout << lo << "\n";
}
