#include <bits/stdc++.h>
using namespace std;

int split(int n, int k)
{
    if (n <= k || (n - k) % 2 == 1) return 0;
    return 1 + split((n - k) / 2, k) + split((n - k) / 2 + k, k);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    cout << split(n, k) + 1 << "\n";
}
