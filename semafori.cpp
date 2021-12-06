#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, l, d, r, g;
    cin >> n >> l;
    vector <vector <int> > lights;
    for (int x = 0; x < n; x++)
    {
        cin >> d >> r >> g;
        lights.push_back({d, r, g});
    }
    int t = 0;
    for (int a = 1; a < l; a++)
    {
        t++;
        if (a == lights[0][0])
        {
            for (int b = 1; b <= lights[0][1]; b++)
            {
                if (t % (lights[0][1] + lights[0][2]) == b)
                {
                    t += lights[0][1] - b + 1;
                    break;
                }
            }
            lights.erase(lights.begin());
        }
    }
    cout << t << endl;
}
