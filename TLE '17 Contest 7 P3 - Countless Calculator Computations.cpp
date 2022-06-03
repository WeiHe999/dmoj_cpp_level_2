#include <bits/stdc++.h>
using namespace std;

double power(double a, int t)
{
    if (t == 1) return a;
    return pow(a, power(a, t - 1));
}

int check(double m, int t, int c)
{
    double a = power(m, t);
    if (a < c) return -1;
    return 1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        int a, b;
        double lo = 1, hi, mi;
        cin >> a >> b;
        hi = b;
        while (lo <= hi)
        {
            mi = (lo + hi) / 2;
            if (abs(mi - 2) < 0.000001) break;
            if (check(mi, a, b) == -1) lo = mi + 0.000001;
            else hi = mi - 0.000001;
        }
        cout << fixed << setprecision(6) << mi << "\n";
    }
}
