#include <bits/stdc++.h>
using namespace std;

long long power(long long a, long long b)
{
    long long s = 1;
    for (int i = 1; i <= b; i++) s *= a;
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long a, b, p1 = 1, p2 = 1;
    cin >> a >> b;
    while (((a - 1) / power(2, p1) + 1) * power(2, p1) <= b) p1++;
    while (((a - 1) / power(5, p2) + 1) * power(5, p2) <= b) p2++;
    cout << min(p1, p2) - 1 << "\n";
}
