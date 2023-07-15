#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, s = 0;
    cin >> n;
    for (long long i = 1; 2 * i <= n; i++) s = max(((n - 2 * i) * (n - 2 * i - 1) * i) / 2, s);
    cout << s << "\n";
}
