#include <bits/stdc++.h>
using namespace std;

long long query(long long l, long long r, vector <vector <long long> > &st)
{
    long long k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, q, v, left, right, l, r, m;
    cin >> n >> q;
    vector <long long> vec1(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    vector <vector <long long> > st(n + 1, vector <long long>(log2(n) + 1));
    for (long long i = 1; i <= n; i++) st[i][0] = vec1[i];
    for (long long k = 1; k <= log2(n); k++)
    {
        for (long long i = 1; i + (1 << (k - 1)) <= n; i++) st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
    }
    for (long long i = 1; i <= q; i++)
    {
        cin >> v >> left >> right;
        long long ans = 0;
        l = left;
        while (ans >= 0)
        {
            r = right;
            ans = -1;
            while (l <= r)
            {
                m = (l + r) / 2;
                if (query(l, m, st) <= v)
                {
                    ans = m;
                    r = m - 1;
                }
                else l = m + 1;
            }
            if (ans >= 1)
            {
                v %= vec1[ans];
                l = ans + 1;
            }
        }
        cout << v << "\n";
    }
}
