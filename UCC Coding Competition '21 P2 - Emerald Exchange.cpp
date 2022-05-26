#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, s = 0, sum = 0;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (a % 2 == 1)
        {
            sum = 0;
            continue;
        }
        sum += a;
        s = max(sum, s);
    }
    cout << s << endl;
}
