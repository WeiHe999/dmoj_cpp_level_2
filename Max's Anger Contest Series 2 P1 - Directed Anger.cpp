#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    char d;
    int l, r;
    cin >> d >> l >> r;
    for (int i = 1; i <= l; i++)
    {
        if (d == 'N') d = 'W';
        else if (d == 'W') d = 'S';
        else if (d == 'S') d = 'E';
        else if (d == 'E') d = 'N';
    }
    for (int i = 1; i <= r; i++)
    {
        if (d == 'N') d = 'E';
        else if (d == 'W') d = 'N';
        else if (d == 'S') d = 'W';
        else if (d == 'E') d = 'S';
    }
    cout << d << "\n";
}
