#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a == c) cout << "y-axis" << endl;
    else if (b == d) cout << "x-axis" << endl;
    else cout << "neither" << endl;
}
