#include <bits/stdc++.h>
using namespace std;

void rotate90Clockwise(vector <vector <char> > &a, int N)
{
    for (int i = 0; i < N / 2; i++) {
        for (int j = i; j < N - i - 1; j++) {
            int temp = a[i + 1][j + 1];
            a[i + 1][j + 1] = a[N - j][i + 1];
            a[N - j][i + 1] = a[N - i][N - j];
            a[N - i][N - j] = a[j + 1][N - i];
            a[j + 1][N - i] = temp;
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int a = 1; a <= t; a++)
    {
        int n, k;
        cin >> n;
        vector <vector <char> > desired(n + 1, vector <char>(n + 1));
        for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) cin >> desired[i][j];
        cin >> k;
        vector <vector <char> > stamp1(k + 1, vector <char>(k + 1)), stamp2(k + 1, vector <char>(k + 1)),
        stamp3(k + 1, vector <char>(k + 1)), stamp4(k + 1, vector <char>(k + 1));
        for (int i = 1; i <= k; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                cin >> stamp1[i][j];
                stamp2[i][j] = stamp1[i][j];
                stamp3[i][j] = stamp1[i][j];
                stamp4[i][j] = stamp1[i][j];
            }
        }
        rotate90Clockwise(stamp2, k);
        rotate90Clockwise(stamp3, k);
        rotate90Clockwise(stamp3, k);
        rotate90Clockwise(stamp4, k);
        rotate90Clockwise(stamp4, k);
        rotate90Clockwise(stamp4, k);
        vector <vector <bool> > vis(n + 1, vector <bool>(n + 1, false));
        for (int i = 1; i <= n - k + 1; i++)
        {
            for (int j = 1; j <= n - k + 1; j++)
            {
                bool flag1 = true, flag2 = true, flag3 = true, flag4 = true;
                for (int x = i; x <= i + k - 1; x++)
                {
                    for (int y = j; y <= j + k - 1; y++)
                    {
                        if (desired[x][y] == '.' && stamp1[x - i + 1][y - j + 1] == '*') flag1 = false;
                        if (desired[x][y] == '.' && stamp2[x - i + 1][y - j + 1] == '*') flag2 = false;
                        if (desired[x][y] == '.' && stamp3[x - i + 1][y - j + 1] == '*') flag3 = false;
                        if (desired[x][y] == '.' && stamp4[x - i + 1][y - j + 1] == '*') flag4 = false;
                    }
                }
                for (int x = i; x <= i + k - 1; x++)
                {
                    if (flag1)
                    {
                        for (int y = j; y <= j + k - 1; y++) if (stamp1[x - i + 1][y - j + 1] == '*') vis[x][y] = true;
                    }
                    if (flag2)
                    {
                        for (int y = j; y <= j + k - 1; y++) if (stamp2[x - i + 1][y - j + 1] == '*') vis[x][y] = true;
                    }
                    if (flag3)
                    {
                        for (int y = j; y <= j + k - 1; y++) if (stamp3[x - i + 1][y - j + 1] == '*') vis[x][y] = true;
                    }
                    if (flag4)
                    {
                        for (int y = j; y <= j + k - 1; y++) if (stamp4[x - i + 1][y - j + 1] == '*') vis[x][y] = true;
                    }
                }
            }
        }
        bool flag = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if ((desired[i][j] == '*' && !vis[i][j]) || (desired[i][j] == '.' && vis[i][j]))
                {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
