#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0, total_s = 0;
    cin >> n;
    vector <int> vec1(n + 1), ans(n + 1);
    int median_p = floor(n / 2.0) + 1;
    for (int i = 1; i <= median_p; i++)
    {
        cout << "? " << i << " " << n << endl;
        cin >> vec1[i];
    }
    for (int i = median_p; i < n; i++)
    {
        cout << "? " << i - median_p + 1 << " " << i << endl;
        cin >> vec1[i + 1];
    }
    for (int i = 1; i < median_p; i++)
    {
        ans[i] = vec1[i] ^ vec1[i + 1];
        s ^= ans[i];
        total_s ^= ans[i];
    }
    for (int i = median_p; i < n; i++)
    {
        ans[i] = s ^ vec1[i + 1];
        s ^= ans[i - median_p + 1] ^ ans[i];
        total_s ^= ans[i];
    }
    ans[n] = total_s ^ vec1[1];
    cout << "! " << ans[1];
    for (int i = 2; i <= n; i++) cout << " " << ans[i];
    cout << "\n";
}
