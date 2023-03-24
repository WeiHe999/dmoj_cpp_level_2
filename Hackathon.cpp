#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, s, t, r;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> s >> t >> r;
        int tmp = n, cnt = 0;
        while (true)
        {
            if (tmp - s * t <= 0)
            {
                cnt += ceil(tmp / (s * 1.0));
                break;
            }
            cnt += t + r;
            tmp -= s * t;
        }
        cout << cnt << "\n";
    }
}
