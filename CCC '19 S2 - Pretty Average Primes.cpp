#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    for (int a = 2; a <= sqrt(n); a++) if (n % a == 0) return false;
    return true;
}

int main()
{
    int c, n;
    cin >> c;
    for (int a = 0; a < c; a++)
    {
        cin >> n;
        n *= 2;
        for (int b = 3; b <= n / 2; b += 2)
        {
            if (!is_prime(b) || !is_prime(n - b)) continue;
            cout << b << ' ' << n - b << endl;
            break;
        }
    }
}
