#include <bits/stdc++.h>
using namespace std;

int n;
vector <vector <double> > vec1(21, vector <double>(21));
vector <bool> vis(1 << 20);
vector <double> dp(1 << 20);

double rec(int d, int s)
{
    if (d == n) return 1.0;
    if (vis[s]) return dp[s];
    vis[s] = true;
    double ans = 0.0;
    for (int i = 0; i < n; i++) if (!(s & (1 << i))) ans = max(vec1[d][i] * rec(d + 1, s | (1 << i)), ans);
    return dp[s] = ans;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> vec1[i][j];
            vec1[i][j] /= 100.0;
        }
    }
    cout << fixed << setprecision(6) << rec(0, 0) * 100 << "\n";
}
