#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, a, b, x = 0, y = 0;
    cin >> r >> c >> a >> b;
    while (a != 0 || b != 0)
    {
        x += a;
        y += b;
        if (x < 0) x = 0;
        if (x > r) x = r;
        if (y < 0) y = 0;
        if (y > c) y = c;
        cout << x << " " << y << "\n";
        cin >> a >> b;
    }
}
