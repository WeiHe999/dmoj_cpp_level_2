#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, maxa = 0;
    string a;
    cin >> n >> a;
    vector <int> pg1(2 * n + 1), pg2(2 * n + 1), ps1(2 * n + 1), ps2(2 * n + 1);
    a = a + a;
    for (int b = 0; b < a.size(); b++)
    {
        if (a[b] == 'g' || a[b] == 'p') pg1[b + 1] = pg1[b] + 1;
        if (a[b] == 's' || a[b] == 'p') ps1[b + 1] = ps1[b] + 1;
    }
    for (int b = a.size(); b > 0; b--)
    {
        if (a[b - 1] == 'g' || a[b - 1] == 'p') pg2[b - 1] = pg2[b] + 1;
        if (a[b - 1] == 's' || a[b - 1] == 'p') ps2[b - 1] = ps2[b] + 1;
    }
    for (int c = 0; c < a.size(); c++)
    {
        maxa = max(max(pg1[c], ps1[c]) + max(pg2[c], ps2[c]), maxa);
        if (maxa >= n)
        {
            maxa = n;
            break;
        }
    }
    cout << maxa << "\n";
}
