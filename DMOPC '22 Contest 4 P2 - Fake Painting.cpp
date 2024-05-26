#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, s1, s2, s3, s4;
    cin >> n >> m;
    vector <vector <int> > vec1(n + 1, vector <int>(m + 1)), vec2(n + 1, vector <int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> vec1[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> vec2[i][j];
    bool flag = true;
    for (int i = 1; i <= floor(n / 2.0); i++)
    {
        for (int j = 1; j <= floor(m / 2.0); j++)
        {
            flag = false;
            s1 = vec2[i][j] - vec1[i][j], s2 = vec2[n - i + 1][j] - vec1[n - i + 1][j], s3 = vec2[i][m - j + 1] - vec1[i][m - j + 1], s4 = vec2[n - i + 1][m - j + 1] - vec1[n - i + 1][m - j + 1];
            if (s1 + s4 == s2 + s3) flag = true;
            s1 = vec2[i][j] - vec1[i][m - j + 1], s2 = vec2[n - i + 1][j] - vec1[n - i + 1][m - j + 1], s3 = vec2[i][m - j + 1] - vec1[i][j], s4 = vec2[n - i + 1][m - j + 1] - vec1[n - i + 1][j];
            if (s1 + s4 == s2 + s3) flag = true;
            s1 = vec2[i][j] - vec1[n - i + 1][j], s2 = vec2[n - i + 1][j] - vec1[i][j], s3 = vec2[i][m - j + 1] - vec1[n - i + 1][m - j + 1], s4 = vec2[n - i + 1][m - j + 1] - vec1[i][m - j + 1];
            if (s1 + s4 == s2 + s3) flag = true;
            if (!flag) break;
        }
        if (!flag) break;
    }
    if (flag && n % 2 == 1)
    {
        for (int j = 1; j <= floor(m / 2.0); j++)
        {
            s1 = vec2[n / 2 + 1][j] - vec1[n / 2 + 1][j], s2 = vec2[n / 2 + 1][m - j + 1] - vec1[n / 2 + 1][m - j + 1];
            if (abs(s1 - s2) % 2 != 0)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag && m % 2 == 1)
    {
        for (int i = 1; i <= floor(n / 2.0); i++)
        {
            s1 = vec2[i][m / 2 + 1] - vec1[i][m / 2 + 1], s2 = vec2[n - i + 1][m / 2 + 1] - vec1[n - i + 1][m / 2 + 1];
            if (abs(s1 - s2) % 2 != 0)
            {
                flag = false;
                break;
            }
        }
    }
    if (flag && n % 2 == 1 && m % 2 == 1)
    {
        s1 = vec2[n / 2 + 1][m / 2 + 1] - vec1[n / 2 + 1][m / 2 + 1];
        if (s1 % 2 != 0) flag = false;
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
