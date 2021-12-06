#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long m, n, k, a, tot_cushions = 0, s;
    cin >> m >> n >> k;
    vector <long long> vec1;
    for (long long x = 0; x < k; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.rbegin(), vec1.rend());
    for (long long b = 0; b < ceil(1.0 * k / m); b++)
    {
        s = 1;
        if (b == ceil(1.0 * k / m) - 1)
        {
            for (long long c = vec1.size() - 1 - (m - 1) * b; c >= ceil(1.0 * k / m); c--)
            {
                tot_cushions += vec1[b] - vec1[c] + s;
                s++;
            }
        }
        else
        {
            for (long long c = vec1.size() - 1 - (m - 1) * b; c > vec1.size() - 1 - (m - 1) * (b + 1); c--)
            {
                tot_cushions += vec1[b] - vec1[c] + s;
                s++;
            }
        }
    }
    cout << tot_cushions << endl;
}
