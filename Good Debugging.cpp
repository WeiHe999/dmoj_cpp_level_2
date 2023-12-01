#include <bits/stdc++.h>
using namespace std;

vector <int> seg, lazy, vec1;

void push_down(int l, int r, int ind)
{
    lazy[2 * ind] = (lazy[2 * ind] + lazy[ind]) % 2;
    lazy[2 * ind + 1] = (lazy[2 * ind + 1] + lazy[ind]) % 2;
    int mid = (l + r) / 2;
    if (lazy[ind])
    {
        seg[2 * ind] = (mid - l + 1) - seg[2 * ind];
        seg[2 * ind + 1] = (r - mid) - seg[2 * ind + 1];
    }
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
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}

void update(int l, int r, int ql, int qr, int val, int ind)
{
    if (l == ql && r == qr)
    {
        seg[ind] = (r - l + 1) - seg[ind];
        lazy[ind] = (lazy[ind] + val) % 2;
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
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
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
        return s1 + s2;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, l, a, b;
    cin >> n >> m >> l;
    seg.resize(4 * n + 2);
    lazy.resize(4 * n + 2);
    vec1.resize(n + 1, 1);
    build(1, n, 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        update(1, n, a, b, 1, 1);
        int left = 1, right = n, mid, ans = -1;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (query(1, n, 1, mid, 1) < l) left = mid + 1;
            else
            {
                ans = mid;
                right = mid - 1;
            }
        }
        if (ans == -1) cout << "AC?\n";
        else cout << ans << "\n";
    }
}
