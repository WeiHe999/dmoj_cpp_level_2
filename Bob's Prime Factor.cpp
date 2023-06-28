#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0, ans;
    cin >> n;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        int tmp = vec1[i], s1 = 0;
        for (int j = 2; j * j <= tmp; j++)
        {
            while (tmp % j == 0)
            {
                s1 = max(j, s1);
                tmp /= j;
            }
        }
        s1 = max(tmp, s1);
        if (s1 > s)
        {
            s = s1;
            ans = vec1[i];
        }
    }
    cout << ans << "\n";
}
