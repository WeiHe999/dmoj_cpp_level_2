#include <bits/stdc++.h>
using namespace std;
int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    long long n;
    cin >> n;
    vector <double> streams;
    double a;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        streams.emplace_back(a);
    }
    long long b;
    double c, left, right, val;
    while (true)
    {
        cin >> a;
        if (a == 77) break;
        if (a == 99)
        {
            cin >> b >> c;
            b--;
            left = c * streams[b ] / 100.0;
            right = streams[b ] - left;
            streams[b] = round(left);
            streams.insert(cbegin(streams) + b+1, round(right));
        }
        if (a == 88)
        {
            cin >> b;
            val = streams[b - 1] + streams[b];
            streams[b - 1] = round(val);
            streams.erase(cbegin(streams) + b);
        }
    }
    for (auto e : streams) cout << round(e) << " ";
}
