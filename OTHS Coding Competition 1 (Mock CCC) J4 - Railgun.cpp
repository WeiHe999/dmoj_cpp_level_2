#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s, t, ans = 0;
    cin >> n >> s >> t;
    vector <int> vec1(n + 1), psa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        psa[i] = psa[i - 1] + vec1[i];
    }
    if (s * t >= n)
    {
        cout << psa[n] << "\n";
        return 0;
    }
    for (int i = 0; i <= t; i++)
    {
        int j = t - i;
        ans = max(psa[s * i] + psa[n] - psa[n - s * j], ans);
    }
    cout << ans << "\n";
}
