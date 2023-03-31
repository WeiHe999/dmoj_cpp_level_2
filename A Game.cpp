#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "0\n";
        return 0;
    }
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    vector <vector <int> > memo(n + 1, vector <int>(n + 1));
    for (int i = 1; i <= n; i++) memo[i][i] = vec1[i];
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n - k; i++)
        {
            int j = i + k;
            if (i + 1 == j) memo[i][j] = max(vec1[i], vec1[j]);
            else memo[i][j] = max(vec1[i] + min(memo[i + 2][j], memo[i + 1][j - 1]), vec1[j] + min(memo[i][j - 2], memo[i + 1][j - 1]));
        }
    }
    cout << memo[1][n] << "\n";
}
