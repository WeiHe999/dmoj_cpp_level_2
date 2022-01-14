#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1, vec2, psa, da;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec2.emplace_back(a);
    }
    for (int b = 0; b < n; b++) psa.emplace_back(vec2[b] - vec1[b]);
    for (int c = 0; c <= n; c++)
    {
        if (c == 0) da.emplace_back(psa[c]);
        else if (c != n) da.emplace_back(psa[c] - psa[c - 1]);
        else da.emplace_back(0 - psa[c - 1]);
    }
    int s = 0;
    for (auto d : da) if (d > 0) s += d;
    cout << s << endl;
}
