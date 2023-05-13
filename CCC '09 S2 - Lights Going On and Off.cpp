#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, a, s = 0;
    cin >> r >> c;
    vector <int> lights(r + 1);
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> a;
            lights[i] += pow(2, c - j) * a;
        }
    }
    unordered_set <int> s1;
    for (int i = r; i >= 1; i--)
    {
        s ^= lights[i];
        s1.insert(s);
    }
    cout << s1.size() << "\n";
}
