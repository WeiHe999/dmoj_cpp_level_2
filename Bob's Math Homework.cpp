#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, s = 1;
    cin >> n;
    for (long long l = 1; l * (l + 1) < 2 * n; l++)
    {
        double a = (1.0 * n - (l * (l + 1)) / 2) / (l + 1);
        if (a - (long long)a == 0.0) s++;
    }
    cout << s << endl;
}
