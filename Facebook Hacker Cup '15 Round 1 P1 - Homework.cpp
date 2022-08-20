#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1(10000001);
    for (int x = 2; x < 10000001; x++)
    {
        if (vec1[x] == 0)
        {
            for (int y = x; y < 10000001; y += x)
            {
                vec1[y]++;
            }
        }
    }
    int t, a, b, k, s;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> a >> b >> k;
        s = 0;
        for (int y = a; y <= b; y++)
        {
            if (vec1[y] == k) s++;
        }
        cout << "Case #" << x + 1 << ": " << s << "\n";
    }
}
