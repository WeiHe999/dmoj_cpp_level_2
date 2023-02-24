#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int a = 1; a <= t; a++)
    {
        int n, k, w;
        cin >> n >> k >> w;
        vector <int> vec1(n + 1);
        for (int x = 1; x <= n; x++) cin >> vec1[x];
        vector <vector <int> > memo(k + 1, vector <int>(n + 1));
        for (int i = 1; i <= k; i++)
        {
            int s = 0;
            for (int j = 1; j <= n; j++)
            {
                s += vec1[j];
                if (j > w) s -= vec1[j - w];
                if (j <= w) memo[i][j] = s;
                else memo[i][j] = max(memo[i][j - 1], memo[i - 1][j - w] + s);
            }
        }
        cout << memo[k][n] << "\n";
    }
}
