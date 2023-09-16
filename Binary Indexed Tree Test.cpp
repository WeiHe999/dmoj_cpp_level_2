#include <bits/stdc++.h>
using namespace std;

void update(long long ind, long long val, long long n, vector <long long> &bit1)
{
    for (long long i = ind; i <= n; i += (i & (-i))) bit1[i] += val;
}

long long query(long long ind, vector <long long> &bit1)
{
    long long s = 0;
    for (long long i = ind; i >= 1; i -= (i & (-i))) s += bit1[i];
    return s;
}

long long MM = 1e5+7;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, a, l, r;
    char c;
    cin >> n >> m;
    vector <long long> bit1(n + 1), bit2(MM + 1);
    for (long long i = 1; i <= n; i++)
    {
        cin >> a;
        update(i, a, n, bit1);
        update(a, 1, MM, bit2);
    }
    for (long long i = 1; i <= m; i++)
    {
        cin >> c;
        if (c == 'C')
        {
            cin >> l >> r;
            long long v = query(l, bit1) - query(l-1, bit1);
            update(l, r - v, n, bit1);
            update(v, -1, MM, bit2);
            update(r, 1, MM, bit2);
        }
        else if (c == 'S')
        {
            cin >> l >> r;
            cout << query(r, bit1) - query(l - 1, bit1) << "\n";
        }
        else
        {
            cin >> l;
            cout << query(l, bit2) << "\n";
        }
    }
}
