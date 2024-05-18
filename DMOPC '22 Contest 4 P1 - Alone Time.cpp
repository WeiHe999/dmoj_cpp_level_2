#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, s = 0;
    cin >> n >> m >> k;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    vec1.emplace_back(m + 1);
    for (int i = 0; i < vec1.size() - 1; i++)
    {
        if (vec1[i + 1] - vec1[i] < k) s = max(vec1[min(i + 2, (int)(vec1.size()) - 1)] - vec1[i] - 1, s);
        s = max(min(vec1[min(i + 2, (int)(vec1.size()) - 1)], vec1[i + 1] + k) - vec1[i] - 1, s);
        s = max(vec1[i + 1] - max(vec1[max(0ll, i - 1)], vec1[i] - k) - 1, s);
    }
    cout << s << "\n";
}
