#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    if (n < 5)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int x = 1; x <= n; x += 2) if (x != 5) cout << x << " ";
    cout << 5 << " " << 4 << " ";
    for (int x = 2; x <= n; x += 2)
    {
        if (x != 4)
        {
            if (x != n && x != n - 1 && n != 5) cout << x << " ";
            else cout << x << endl;
        }
    }
}
