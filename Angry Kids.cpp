#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, minimum = INT_MAX, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (minimum > a)
        {
            s++;
            minimum = a;
        }
    }
    cout << s << "\n";
}
