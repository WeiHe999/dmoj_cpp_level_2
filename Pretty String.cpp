#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string a;
    cin >> a;
    int gaps = 0, s = 0;
    for (int x = 1; x < a.size(); x++)
    {
        if (isupper(a[x]))
        {
            s += max(0, 4 - gaps);
            gaps = 0;
        }
        else
        {
            gaps++;
            if (gaps == 5) gaps = 0;
        }
    }
    cout << s << "\n";
}
