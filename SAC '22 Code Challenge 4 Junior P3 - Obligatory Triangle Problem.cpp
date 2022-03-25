#include <bits/stdc++.h>
using namespace std;

#define p 3.14159265358979323846

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, x, y, ind = -1;
    double min_e = 361;
    cin >> n >> a;
    for (long long b = 0; b < n; b++)
    {
        cin >> x >> y;
        double angle = atan2(y*1.0, x) * 180 / p;
        if (angle < 0) angle += 360.0;
        double c = abs(angle - a);
        if (c > 180) c = 360 - c;
        if (c < min_e)
        {
            min_e = c;
            ind = b + 1;
        }
    }
    cout << ind << endl;
}
