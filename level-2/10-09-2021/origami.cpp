#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long n, k, pieces, s1, s2, s;
    cin >> n >> k;
    s1 = ceil(log2(k));
    s2 = floor(log2(n));
    if (s1 < s2) s = s1;
    else s = s2;
    pieces = pow(2, s);
    cout << (long long)(ceil(((n - pieces) * 1.0) / k) + s) << endl;
}
