#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, s = 0;
    cin >> n >> a >> b;
    for (int x = 1; x <= n; x++)
    {
        if (x % 2 == 1) s += a;
        else s += b;
    }
    cout << s << endl;
}
