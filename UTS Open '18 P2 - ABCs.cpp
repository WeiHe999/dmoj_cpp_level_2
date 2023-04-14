#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> a(4), b(4), c(4);
    for (int j = 1; j <= 3; j++)
    {
        cin >> a[j];
        if (j == 3) a[0] = a[j];
    }
    for (int j = 1; j <= 3; j++) cin >> b[j];
    for (int j = 1; j <= 3; j++) cin >> c[j];
    int ans = 0;
    for (int k = 0; k <= 2; k++)
    {
        for (int i = 1; i <= 3 - k; i++)
        {
            bool flag = true;
            int s = 0;
            for (int j = i; j <= i + k; j++)
            {
                if (b[j] != a[j - 1])
                {
                    flag = false;
                    break;
                }
                s += c[j];
            }
            if (flag) ans = max(s, ans);
        }
    }
    cout << ans << "\n";
}
