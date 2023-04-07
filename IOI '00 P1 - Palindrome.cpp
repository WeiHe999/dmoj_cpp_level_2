#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    string str1, str2;
    cin >> n >> str1;
    str2 = str1;
    reverse(str2.begin(), str2.end());
    vector <vector <int> > memo(2, vector <int>(n + 1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1]) memo[1][j] = memo[0][j - 1] + 1;
            else memo[1][j] = max(memo[0][j], memo[1][j - 1]);
        }
        for (int x = 0; x <= n; x++)
        {
            memo[0][x] = memo[1][x];
            memo[1][x] = 0;
        }
    }
    cout << n - memo[0][n] << "\n";
}
