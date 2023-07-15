#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, x, y, w, h, cnt = 0;
    bool s;
    cin >> n >> m;
    vector <vector <bool> > da(n, vector <bool>(n));
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y >> w >> h;
        w += x, h += y;
        if (da[x][y]) da[x][y] = false;
        else da[x][y] = true;
        if (h < n)
        {
            if (da[x][h]) da[x][h] = false;
            else da[x][h] = true;
        }
        if (w < n)
        {
            if (da[w][y]) da[w][y] = false;
            else da[w][y] = true;
        }
        if (h < n && w < n)
        {
            if (da[w][h]) da[w][h] = false;
            else da[w][h] = true;
        }
    }
    for (int i = 0; i < n; i++)
    {
        s = false;
        for (int j = 0; j < n; j++)
        {
            if (da[i][j])
            {
                if (s) s = false;
                else s = true;
            }
            da[i][j] = s;
        }
    }
    for (int j = 0; j < n; j++)
    {
        s = false;
        for (int i = 0; i < n; i++)
        {
            if (da[i][j])
            {
                if (s) s = false;
                else s = true;
            }
            da[i][j] = s;
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (da[i][j]) cnt++;
    cout << cnt << "\n";
}
