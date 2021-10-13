#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int x, y, z;
    cin >> x >> y >> z;
    for (int a = 0; a < y; a++)
    {
        if ((a * x) % y == z)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
