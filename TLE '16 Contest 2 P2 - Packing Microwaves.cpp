#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, x, y, z, a, b, c, maxa = LLONG_MIN;
    cin >> n >> x >> y >> z >> a >> b >> c;
    vector <vector <long long> > permutations = {{x, y, z}, {x, z, y}, {y, x, z}, {y, z, x}, {z, x, y}, {z, y, x}};
    for (auto d : permutations)
    {
        maxa = max((a / d[0]) * (b / d[1]) * (c / d[2]), maxa);
    }
    if (maxa == 0)
    {
        cout << "SCAMMED" << endl;
    }
    else
    {
        cout << ceil((n * 1.0) / maxa) << endl;
    }
}
