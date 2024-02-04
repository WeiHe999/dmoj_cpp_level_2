#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    if (k == n)
    {
        for (int i = 1; i <= n; i++) cout << i << " ";
        cout << "\n";
    }
    else
    {
        cout << n << " ";
        for (int i = 2; i <= k; i++) cout << i << " ";
        cout << 1 << " ";
        for (int i = k + 2; i <= n; i++) cout << i - 1 << " ";
        cout << "\n";
    }
}
