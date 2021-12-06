#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int m, a;
    int s;
    for (int x = 0; x < 5; x++)
    {
        cin >> m;
        s = ((m + 1) * (m + 2)) / 2;
        for (int b = 0; b < m; b++)
        {
            cin >> a;
            s -= a;
        }
        cout << s << endl;
    }
}
