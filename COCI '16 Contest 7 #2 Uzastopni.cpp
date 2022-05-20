#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, sum = 1;
    cin >> n;
    for (long long i = 2; ((i + 1) * i) / 2 <= n; i++)
    {
        sum += i;
        if ((n - sum) % i == 0) cout << ((n - sum) / i + 1) << " " << ((n - sum + 1) / i + i) << endl;
    }
}
