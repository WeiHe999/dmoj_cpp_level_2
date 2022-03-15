#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b;
    cin >> n >> a >> b;
    for (int x = 0; x < b; x++)
    {
        n -= a;
        cout << n << endl;
    }
}
