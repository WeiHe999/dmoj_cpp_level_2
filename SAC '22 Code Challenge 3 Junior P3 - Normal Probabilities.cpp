#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    char a;
    cin >> n;
    double b = 1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (a == 'A') continue;
        if (a == 'B') b *= (0.8);
        if (a == 'C') b *= (0.6);
        if (a == 'D') b *= (0.4);
        if (a == 'E') b *= (0.2);
    }
    cout << fixed << setprecision(6) << b << endl;
}
