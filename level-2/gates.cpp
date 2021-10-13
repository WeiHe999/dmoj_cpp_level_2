#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int g, p, plane, res = 0;
    cin >> g >> p;
    vector <int> pos;
    pos.assign(g, 0);
    for (int i = 0; i < p; i++)
    {
        cin >> plane;
        while (plane > 0 && pos[plane])
        {
            pos[plane]++;
            plane -= pos[plane] - 1;
        }
        if (plane <= 0) break;
        pos[plane]++;
        res++;
    }
    cout << res << endl;
}
