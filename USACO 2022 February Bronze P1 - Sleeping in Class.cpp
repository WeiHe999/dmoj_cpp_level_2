#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long t, n, a;
    cin >> t;
    for (long long x = 0; x < t; x++)
    {
        cin >> n;
        vector <long long> psa = {0};
        unordered_set <long long> s1;
        for (long long y = 1; y < n+1; y++)
        {
            cin >> a;
            psa.emplace_back(psa[y - 1] + a);
            s1.insert(psa[y - 1] + a);
        }
        long long total = psa.back();
        if (total == psa[1])
        {
            cout << 0 << endl;
        }
        else
        {
            for (auto b = 1; b <= n; b++)
            {
                bool f = true;
                if (psa[b] > 0 && total % psa[b] == 0)
                {
                    for (long long c = 2; c <= total / psa[b]; c++)
                    {
                        if (s1.count(psa[b] * c) == 0)
                        {
                            f = false;
                            break;
                        }
                    }
                    if (f)
                    {
                        cout << n - (total / psa[b]) << endl;
                        break;
                    }
                }
            }
        }
    }
}
