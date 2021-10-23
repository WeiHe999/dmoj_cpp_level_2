#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int p, a, b, max_x = INT_MIN, min_x = INT_MAX, max_y = INT_MIN, min_y = INT_MAX;
    cin >> p;
    for (int x = 0; x < p; x++)
    {
        cin >> a >> b;
        if (a > max_x) max_x = a;
        if (a < min_x) min_x = a;
        if (b > max_y) max_y = b;
        if (b < min_y) min_y = b;
    }
    cout << 2 * (max_x + max_y - min_x - min_y) << endl;
}
