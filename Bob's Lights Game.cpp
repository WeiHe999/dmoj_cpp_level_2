#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, l, r, s = 0;
    cin >> n >> m;
    vector <int> lights(n + 1, 0), dif_vec(n + 2, 0);
    for (int x = 0; x < m; x++)
    {
        cin >> l >> r;
        dif_vec[l]++;
        dif_vec[r + 1]--;
    }
    for (int a = 1; a < n + 1; a++)
    {
        lights[a] = lights[a - 1] + dif_vec[a];
        if (abs(lights[a]) % 2 == 1) s++;
    }
    cout << endl;
    cout << s << endl;
}
