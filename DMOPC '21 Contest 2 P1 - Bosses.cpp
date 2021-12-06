#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    long long n, h, p, a, c = 0, d = 0;
    cin >> n >> h >> p;
    vector <int> levels;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        levels.emplace_back(a);
    }
    sort(levels.begin(), levels.end());
    for (int i = 0; i < levels.size(); i++)
    {
        if (((h * 1.0) / (levels.size() - i)) <= (p * 1.0))
        {
            if (levels[i] - c > 0) c += levels[i] - c;
        }
        else
        {
            if (levels[i] - c > 0) d += levels[i] - c;
        }
    }
    cout << c * h + d * p << endl;
}
