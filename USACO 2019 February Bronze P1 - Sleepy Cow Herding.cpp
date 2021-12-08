#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (c == a + 2) cout << 0 << endl;
    else if (b == a + 2 || c == b + 2) cout << 1 << endl;
    else cout << 2 << endl;
    cout << max(b - a, c - b) - 1 << endl;
}
