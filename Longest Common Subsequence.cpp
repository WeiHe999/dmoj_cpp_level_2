#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    vector <int> vec1(n + 1), vec2(m + 1);
    vector <vector <int> > memo(n + 1, vector <int>(m + 1));
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 1; i <= m; i++) cin >> vec2[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (vec1[i] == vec2[j]) memo[i][j] = memo[i - 1][j - 1] + 1;
            else memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
        }
    }
    cout << memo[n][m] << "\n";
}
