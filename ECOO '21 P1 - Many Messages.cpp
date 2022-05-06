#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    for (int x = 0; x < 3; x++)
    {
        a += b;
        if (a >= c)
        {
            cout << a << endl;
            return 0;
        }
    }
    cout << "Who knows..." << endl;
}
