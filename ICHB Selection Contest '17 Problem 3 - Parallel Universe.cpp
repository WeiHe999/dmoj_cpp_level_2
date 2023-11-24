#include <bits/stdc++.h>
using namespace std;

const unsigned int MM = 1e5 + 2;
unsigned int seg[4*MM], vec1[MM];

void build(unsigned int l, unsigned int r, unsigned int ind)
{
    if (l == r)
    {
        seg[ind] = vec1[l];
        return;
    }
    unsigned int mid = (l + r) / 2;
    build(l, mid, 2 * ind);
    build(mid + 1, r, 2 * ind + 1);
    seg[ind] = seg[2 * ind] & seg[2 * ind + 1];
}

void update(unsigned int l, unsigned int r, unsigned int pos, unsigned int val, unsigned int ind)
{
    if (l == pos && r == pos)
    {
        seg[ind] = val;
        return;
    }
    unsigned int mid = (l + r) / 2;
    if (pos <= mid) update(l, mid, pos, val, 2 * ind);
    else update(mid + 1, r, pos, val, 2 * ind + 1);
    seg[ind] = seg[2 * ind] & seg[2 * ind + 1];
}

unsigned int query(unsigned int l, unsigned int r, unsigned int ql, unsigned int qr, unsigned int val, unsigned int ind)
{
    if (l == ql && r == qr) return val & seg[ind];
    unsigned int mid = (l + r) / 2;
    if (qr <= mid) return val & query(l, mid, ql, qr, val, 2 * ind);
    else if (ql > mid) return val & query(mid + 1, r, ql, qr, val, 2 * ind + 1);
    return val & query(l, mid, ql, mid, val, 2 * ind) & query(mid + 1, r, mid + 1, qr, val, 2 * ind + 1);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    unsigned int n, q, x, y, z;
    cin >> n >> q;
  
    for (unsigned int i = 1; i <= n; i++) cin >> vec1[i];
    build(1, n, 1);
    char c;
    for (unsigned int i = 1; i <= q; i++)
    {
        cin >> c;
        if (c == 'U')
        {
            cin >> x >> y;
            update(1, n, x, y, 1);
        }
        else
        {
            cin >> x >> y >> z;
            cout << query(1, n, x, y, z, 1) << "\n";
        }
    }
}
