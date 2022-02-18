#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int w, s = 1;
    cin >> w;
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    if (w >= 26)
    {
        w -= 26;
        for (auto a : alpha) cout << a << " ";
    }
    else
    {
        for (int a = 0; a < w; a++) cout << alpha[a] << " ";
        cout << endl;
        return 0;
    }
    if (w >= 26 * 26)
    {
        w -= (26 * 26);
        for (auto b : alpha)
        {
            for (auto c : alpha) cout << b << c << " ";
        }
    }
    else
    {
        for (int b = 0; b < (w / 26); b++)
        {
            for (int c = 0; c < 26; c++) cout << alpha[b] << alpha[c] << " ";
        }
        for (int d = 0; d < (w % 26); d++) cout << "z" << alpha[d] << " ";
        cout << endl;
        return 0;
    }
    int i1 = 0, i2 = 0, i3 = 0;
    while (w != 0)
    {
        cout << alpha[i1] << alpha[i2] << alpha[i3] << " ";
        i3++;
        if (i3 == 26)
        {
            i3 = 0;
            i2++;
        }
        if (i2 == 26)
        {
            i2 = 0;
            i1++;
        }
        w--;
    }
    cout << endl;
}
