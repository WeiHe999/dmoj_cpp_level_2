#include <bits/stdc++.h>
using namespace std;
     
int main()
{
    int n, c[100], d[100];
    string t[100];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> c[i] >> d[i];
    int a = -999999999, b = 999999999;
    for (int i = n - 1; i >= 0; i--)
    {
        if (t[i] == "none")
        {
            a = max(a, c[i]);
            b = min(b, d[i]);
        }
        if (t[i] == "off")
        {
            a += c[i];
            b += d[i];
        }
        if (t[i] == "on")
        {
            a -= d[i];
            b -= c[i];
            a = max(0, a);
        }
    }
    cout << a << " " << b << endl;
    a = -999999999, b = 999999999;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == "none")
        {
            a = max(a, c[i]);
            b = min(b, d[i]);
        }
        if (t[i] == "on")
        {
            a += c[i];
            b += d[i];
        }
        if (t[i] == "off")
        {
            a -= d[i];
            b -= c[i];
            a = max(0, a);
        }
    }
    cout << a << " " << b << endl;
}
