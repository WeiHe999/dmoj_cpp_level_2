#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, s1 = 100, s2 = 100;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        if (a < b) s1 -= b;
        if (a > b) s2 -= a;
    }
    cout << s1 << "\n" << s2 << "\n";
}
