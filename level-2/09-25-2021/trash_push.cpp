#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int t;
    long long n, k;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> n >> k;
        if (n % k == 0) cout << n / k << endl;
        else cout << n / k + 1 << endl;
    }
}
