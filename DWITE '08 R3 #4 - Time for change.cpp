#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int x = 1; x <= 5; x++)
    {
        int m, n;
        cin >> m >> n;
        vector <int> vec1(n + 1), memo(m + 1, 1e9);
        for (int i = 1; i <= n; i++) cin >> vec1[i];
        memo[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                if (memo[j] == 1e9) continue;
                if (j + vec1[i] <= m) memo[j + vec1[i]] = min(memo[j] + 1, memo[j + vec1[i]]);
            }
        }
        cout << memo[m] << "\n";
    }
}
