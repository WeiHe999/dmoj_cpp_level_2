#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, d, ans = 1, s = 0, cur = 1;
    cin >> n >> d;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 1; i < n; i++)
    {
        if (abs(vec1[i + 1] - vec1[i]) <= d)
        {
            cur++;
            s = max(cur, s);
        }
        else
        {
            ans++;
            cur = 1;
        }
    }
    cout << ans << "\n" << s << "\n";
}
