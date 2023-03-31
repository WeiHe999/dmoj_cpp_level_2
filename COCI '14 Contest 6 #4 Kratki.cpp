#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    if (k * k < n)
    {
        cout << "-1\n";
        return 0;
    }
    for (int i = n; i >= 1; i -= k) for (int j = max(1LL, i - k + 1); j <= i; j++) cout << j << " ";
    cout << "\n";
}
