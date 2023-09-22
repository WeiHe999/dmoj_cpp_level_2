#include <bits/stdc++.h>
using namespace std;

int i, s, x, y, a, b;
vector <vector <int> > bit(1025, vector <int>(1025));

void update(int r, int c, int val)
{
    for (int i = r; i <= s; i += (i & -i)) for (int j = c; j <= s; j += (j & -j)) bit[i][j] += val;
}

int query(int r, int c)
{
    int s = 0;
    for (int i = r; i >= 1; i -= (i & -i)) for (int j = c; j >= 1; j -= (j & -j)) s += bit[i][j];
    return s;
}

int query_sum(int r1, int c1, int r2, int c2)
{
    return query(r2, c2) - query(r1 - 1, c2) - query(r2, c1 - 1) + query(r1 - 1, c1 - 1);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    do
    {
        cin >> i;
        if (i == 0) cin >> s;
        if (i == 1)
        {
            cin >> x >> y >> a;
            update(x + 1, y + 1, a);
        }
        if (i == 2)
        {
            cin >> x >> y >> a >> b;
            cout << query_sum(x + 1, y + 1, a + 1, b + 1) << "\n";
        }
    } while (i != 3);
}
