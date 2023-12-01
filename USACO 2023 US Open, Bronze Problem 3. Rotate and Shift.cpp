#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, t;
    cin >> n >> k >> t;
    vector <int> vec1(n + 1), ans(n + 1);
    for (int i = 1; i <= k; i++) cin >> vec1[i];
    vec1[k + 1] = n;
    for (int i = 1; i <= k; i++)
    {
        for (int j = vec1[i]; j < vec1[i + 1]; j++)
        {
            int tmp = j - vec1[i] - t;
            int diff = vec1[i + 1] - vec1[i];
            tmp = (tmp % diff + diff) % diff;
            ans[(vec1[i] + tmp + t) % n] = j;
        }
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}
