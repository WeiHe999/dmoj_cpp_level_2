#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, ind;
    cin >> n;
    for (long long k = 63; k >= 0; k--)
    {
        if (n & (1LL << k))
        {
            ind = k;
            break;
        }
    }
    for (int i = 0; i <= ind; i++) cout << 1;
    cout << "\n";
}
