#include <bits/stdc++.h>
using namespace std;

long long distance(long long x1, long long y1)
{
    return pow(x1, 2) + pow(y1, 2);
}

int main()
{
    long long n, q, a, b, c, s;
    cin >> n >> q;
    vector <long long> houses;
    for (long long x = 0; x < n; x++)
    {
        cin >> a >> b;
        houses.emplace_back(distance(a, b));
    }
    sort(houses.begin(), houses.end());
    for (long long y = 0; y < q; y++)
    {
        cin >> c;
        cout << upper_bound(houses.begin(), houses.end(), pow(c, 2)) - houses.begin() << endl;
    }
}
