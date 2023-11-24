#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (c > a)
        {
            cout << "NO\n";
            continue;
        }
        if (((a > 0 && c > 0) || b % 2 == 0) && (a - c) % 2 == 0)
        {
            cout << "YES\n";
            continue;
        }
        if ((a - c) % 2 == 1)
        {
            cout << "NO\n";
            continue;
        }
        if (a > 0 || b % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }
}
