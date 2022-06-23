#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m;
    cin >> n >> m;
    cout << m - ((m / n) * n) + 1 << "\n";
}
