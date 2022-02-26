#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int f, n, b, x, y, z;
    cin >> f >> n >> b >> x >> y >> z;
    cout << x + y + z << " " << f * x + n * y + b * z << endl;
}
