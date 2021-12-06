#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    int n, x, odd = 0, even = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        if (x % 2 == 0) even++;
        else odd++;
    }
    while (odd > even)
    {
        odd = odd - 2;
        even++;
    }
    if (even > odd + 1) even = odd + 1;
    cout << even + odd << endl;
}
