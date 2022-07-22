#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    double ans = INT_MAX;
    sort(vec1.begin(), vec1.end());
    for (int i = 1; i <= n - 1; i++)
    {
        int v1 = abs(vec1[i] - vec1[i - 1]);
        int v2 = abs(vec1[i + 1] - vec1[i]);
        ans = min(ans, v1 / 2.0 + v2 / 2.0);
    }
    cout << setprecision(1) << fixed << ans << "\n";
}
