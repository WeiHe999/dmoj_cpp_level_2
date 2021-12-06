#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    long long n, a;
    cin >> n;
    long long count_e = 0, count_o = 0;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        if (a % 2 == 0) count_e += (a / 2);
        else count_o += (a / 2) + 1;
    }
    if (count_e > count_o) cout << "Duke" << endl;
    else cout << "Alice" << endl;
}
