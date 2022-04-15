#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, a, b, c, d;
    cin >> t;
    double lower_bound, upper_bound;
    for (long long x = 0; x < t; x++)
    {
        cin >> a >> b >> c >> d;
        lower_bound = (a * 1.0) / (b - a);
        upper_bound = (d - c) / (c * 1.0);
        if (lower_bound < 0 || upper_bound <0) cout << "NO" << endl;
        else
        {
            if (upper_bound > lower_bound) cout << "YES" << endl;
            else cout << "NO" << endl;            
        }
    }
}
