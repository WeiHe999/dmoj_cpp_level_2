#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, r, a, sum = 0, ans = 0;
    cin >> n >> k >> r;
    vector <int> vec1(n + 1);
    for (int x = 0; x < k; x++)
    {
        cin >> a;
        if (a <= r) sum++;
        vec1[a] = 1;
    }
    for (int y = 1; y <= vec1.size() - r + 1; y++)
    {
        if (sum < 2)
        {
            int ind = y + r - 1;
            if (ind > n) break;
            if (sum == 1)
            {
                if (vec1[ind] == 0)
                {
                    vec1[ind] = 1;
                }
                else
                {
                    vec1[ind - 1] = 1;
                }
                sum++;
            }
            else
            {
                vec1[ind] = 1;
                vec1[ind - 1] = 1;
                ans++;
                sum += 2;
            }
            ans++;
        }
        sum -= vec1[y] - vec1[y + r];
    }
    cout << ans << "\n";
}
