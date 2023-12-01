#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> seg, lazy, vec1;

void push_down(int l, int r, int ind)
{
    lazy[2 * ind] += lazy[ind];
    lazy[2 * ind + 1] += lazy[ind];
    seg[2 * ind] += lazy[ind];
    seg[2 * ind + 1] += lazy[ind];
    if (seg[2 * ind] < 0) seg[2 * ind] = 0;
    if (seg[2 * ind + 1] < 0) seg[2 * ind + 1] = 0;
    lazy[ind] = 0;
}

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

void update(int l, int r, int ql, int qr, int val, int ind)
{
    if (l == ql && r == qr)
    {
        seg[ind] += val;
        lazy[ind] += val;
        if (seg[ind] < 0) seg[ind] = 0;
        return;
    }
    push_down(l, r, ind);
    int mid = (l + r) / 2;
    if (qr <= mid) update(l, mid, ql, qr, val, 2 * ind);
    else if (ql > mid) update(mid + 1, r, ql, qr, val, 2 * ind + 1);
    else
    {
        update(l, mid, ql, mid, val, 2 * ind);
        update(mid + 1, r, mid + 1, qr, val, 2 * ind + 1);
    }
    seg[ind] = min(seg[2 * ind], seg[2 * ind + 1]);
}

int query(int l, int r, int ql, int qr, int ind)
{
    if (l == ql && r == qr) return seg[ind];
    push_down(l, r, ind);
    int mid = (l + r) / 2;
    if (qr <= mid) return query(l, mid, ql, qr, 2 * ind);
    else if (ql > mid) return query(mid + 1, r, ql, qr, 2 * ind + 1);
    else
    {
        int s1 = query(l, mid, ql, mid, 2 * ind), s2 = query(mid + 1, r, mid + 1, qr, 2 * ind + 1);
        return min(s1, s2);
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b, c;
    cin >> n >> q;
    seg.resize(4 * n + 2);
    lazy.resize(4 * n + 2);
    vec1.resize(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    build(1, n, 1);
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b >> c;
        update(1, n, a, b, -c, 1);
        cout << query(1, n, a, b, 1) << " " << query(1, n, 1, n, 1) << "\n";
    }
}
