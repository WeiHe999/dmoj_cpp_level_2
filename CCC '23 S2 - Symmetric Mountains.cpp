#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    vector <vector <int> > memo(n + 1, vector <int>(n + 1, 1e9));
    for (int x = 1; x <= n; x++)
    {
        cin >> vec1[x];
        memo[x][x] = 0;
        if (x != 1) memo[x - 1][x] = abs(vec1[x] - vec1[x - 1]);
    }
    for (int k = 2; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (i + k <= n) memo[i][i + k] = memo[i + 1][i + k - 1] + abs(vec1[i] - vec1[i + k]);
        }
    }
    vector <int> res(n + 1, 1e9);
    for (int i = 1; i <= n; i++) for (int j = i; j <= n; j++) res[j - i + 1] = min(memo[i][j], res[j - i + 1]);
    for (int x = 1; x <= n; x++) cout << res[x] << " ";
    cout << "\n";
}
