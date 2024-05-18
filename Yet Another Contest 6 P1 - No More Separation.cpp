#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a = 1, b = a + 1;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cout << a << " " << b << "\n";
        b++;
        if (b == n + 1)
        {
            a++;
            b = a + 1;
        }
    }
}
