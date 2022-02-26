#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, x, y, s1 = 0, s2 = 0;
    cin >> n >> a >> b;
    for (int z = 0; z < n; z++)
    {
        cin >> x >> y;
        if (a > x) s1++;
        else s1 += 2;
        if (b > y) s2++;
        else s2 += 2;
    }
    if (s1 < s2) cout << "Andrew wins!" << endl;
    else if (s1 > s2) cout << "Tommy wins!" << endl;
    else cout << "Tie!" << endl;
}
