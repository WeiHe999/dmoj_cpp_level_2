#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m;
    cin >> m;
    double a = 12, b = -5, c = 1 - m;
    cout << fixed << setprecision(6) << (((-1 * b) + sqrt(pow(b, 2) - (4 * a * c))) / (2 * a)) << endl;
}
