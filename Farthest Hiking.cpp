#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n, u, f, d, b = 0, c = 0;
    cin >> m >> n >> u >> f >> d; cin.ignore();
    string s;
    getline(cin, s);
    for (auto a : s)
    {
        if (a == 'u' || a == 'd')
        {
            if (b + u + d > m) break;
            b += u + d;
            c++;
        }
        if (a == 'f')
        {
            if (b + f + f > m) break;
            b += f + f;
            c++;
        }
    }
    cout << c << endl;
}
