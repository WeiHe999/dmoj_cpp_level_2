#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        if ((a>=2 && b>=4) || (a>=4 && b>=2)) cout << "good\n";
        else if (a>=7 && b>=1) cout << "good\n";
        else cout << "bad\n";
    }
}
