#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n;
    cin >> n;
    while (true)
    {
        bool flag = true;
        for (long long x = 2; x * x <= n; x++)
        {
            if (n % x == 0)
            {
                flag = false;
                break;
            }
        }
        if (flag && n != 1)
        {
            cout << n << endl;
            break;
        }
        n++;
    }
}
