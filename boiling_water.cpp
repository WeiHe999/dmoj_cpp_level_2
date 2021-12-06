#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int b;
    cin >> b;
    cout << b * 5 - 400 << endl;
    if (b * 5 - 400 > 100) cout << -1 << endl;
    else if (b * 5 - 400 < 100) cout << 1 << endl;
    else cout << 0 << endl;
}
