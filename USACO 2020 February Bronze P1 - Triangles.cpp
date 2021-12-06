#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, a, b;
    cin >> n;
    vector <long long> x, y;
    for (long long i = 0; i < n; i++)
    {
        cin >> a >> b;
        x.emplace_back(a);
        y.emplace_back(b);
    }
    long long best = -1;
    for (long long i = 0; i < n; i++)
    {
        for (long long j = 0; j < n; j++)
        {
            for (long long k = 0; k < n; k++)
            {
                if (y[i] == y[j] && x[i] == x[k])
                {
                    long long area = (x[j] - x[i]) * (y[k] - y[i]);
                    if (area < 0) area *= -1;
                    if (area > best) best = area;
                }
            }
        }
    }
    cout << best << endl;
}
