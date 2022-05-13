#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 1, sign = 1;
    cin >> n;
    cout << s << " ";
    for (int x = n - 1; x > 0; x--)
    {
        s += sign * x;
        cout << s << " ";
        sign *= -1;
    }
    cout << endl;
}
