#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5+2;
vector <int> seg(4 * MM), vec1(MM);

void build(int l, int r, int ind)
{
    if (l == r)
    {
        seg[ind] = vec1[l];
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * ind);
    build(mid + 1, r, 2 * ind + 1);
    seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]);
}

void update(int l, int r, int pos, int val, int ind)
{
    if (l == pos && r == pos)
    {
        seg[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(l, mid, pos, val, 2 * ind);
    else update(mid + 1, r, pos, val, 2 * ind + 1);
    seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]);
}

int query(int l, int r, int ql, int qr, int ind)
{
    if (l == ql && r == qr) return seg[ind];
    int mid = (l + r) / 2;
    if (qr <= mid) return query(l, mid, ql, qr, 2 * ind);
    else if (ql > mid) return query(mid + 1, r, ql, qr, 2 * ind + 1);
    else return min(query(l, mid, ql, mid, 2 * ind), query(mid + 1, r, mid + 1, qr, 2 * ind + 1));
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    char c;
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> a >> b;
        if (c == 'M') update(1, n, a + 1, b, 1);
        else cout << query(1, n, a + 1, b + 1, 1) << "\n";
    }
}
