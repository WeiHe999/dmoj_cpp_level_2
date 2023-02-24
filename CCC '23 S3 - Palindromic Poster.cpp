#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, r, c;
    cin >> n >> m >> r >> c;
    vector <vector <char> > output(n + 1, vector <char>(m + 1));
    if ((0 < r && r < n && 0 < c && c < m) || (r == n && c == m))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i <= r || j <= c) cout << "a";
                else cout << "b";
            }
            cout << "\n";
        }
    }
    else if (r == 0 && c == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i < n && j < m) cout << "a";
                else if (i == n && j == m) cout << "b";
                else cout << "c";
            }
            cout << "\n";
        }
    }
    else if ((r == n && c == 0) || (r == 0 && c == m))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if ((r == n && i < n) || (c == m && j < m)) cout << "a";
                else cout << "b";
            }
            cout << "\n";
        }
    }
    else if (r == n)
    {
        if (m % 2 == 0)
        {
            if (c % 2 == 1) cout << "IMPOSSIBLE\n";
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (i < n || (j > (m / 2) - (c / 2) && j <= (m / 2) + (c / 2))) cout << "a";
                        else cout << "b";
                    }
                    cout << "\n";
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (i < n || (j == m / 2 + 1 && c % 2 == 1) || (j > (m / 2) - (c / 2) && j <= (m / 2) + (c / 2) + 1 && j != m / 2 + 1)) cout << "a";
                    else cout << "b";
                }
                cout << "\n";
            }
        }
    }
    else if (c == m)
    {
        if (n % 2 == 0)
        {
            if (r % 2 == 1) cout << "IMPOSSIBLE\n";
            else
            {
                for (int i = 1; i <= n; i++)
                {
                    for (int j = 1; j <= m; j++)
                    {
                        if (j < m || (i > (n / 2) - (r / 2) && i <= (n / 2) + (r / 2))) cout << "a";
                        else cout << "b";
                    }
                    cout << "\n";
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    if (j < m || (i == n / 2 + 1 && r % 2 == 1) || (i > (n / 2) - (r / 2) && i <= (n / 2) + (r / 2) + 1 && i != n / 2 + 1)) cout << "a";
                    else cout << "b";
                }
                cout << "\n";
            }
        }
    }
    else if (r == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (j <= c) cout << "a";
                else if (i == n) cout << "b";
                else cout << "c";
            }
            cout << "\n";
        }
    }
    else if (c == 0)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i <= r) cout << "a";
                else if (j == m) cout << "b";
                else cout << "c";
            }
            cout << "\n";
        }
    }
}
