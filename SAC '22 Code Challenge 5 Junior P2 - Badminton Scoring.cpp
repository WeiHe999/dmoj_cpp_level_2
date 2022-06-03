#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, s = 0;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        if (a > b) s++;
    }
    cout << s << "\n";
}
