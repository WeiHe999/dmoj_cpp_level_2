#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b, s = 2;
    cin >> a >> b;
    while (a - b >= 0)
    {
        int tmp = a;
        a = b;
        b = tmp - b;
        s++;
    }
    cout << s << "\n";
}
