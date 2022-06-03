#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, c, a;
    cin >> n >> c;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        cout << a + 2 * c << " ";
    }
}
