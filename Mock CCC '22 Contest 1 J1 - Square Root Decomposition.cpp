#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    b = b * b;
    c = c * c;
    if (abs(b - a) < abs(c - a)) cout << 1 << endl;
    else cout << 2 << endl;
}
