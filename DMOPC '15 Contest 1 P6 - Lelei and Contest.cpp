#include <bits/stdc++.h>
using namespace std;

vector <long long> seg, lazy, vec1;

void push_down(long long l, long long r, long long ind)
{
    long long val = lazy[ind];
    long long mid = (l + r)/2;
    // left child
    seg[2*ind] += (mid - l + 1) * val;
    lazy[2*ind] += val;
    // right child
    seg[ 2 * ind + 1] += (r - mid) * val;
    lazy[2 * ind + 1] += val;
    // clear lazy of current node
    lazy[ind] = 0;
}

void build(long long l, long long r, long long ind)
{
    if (l == r)
    {
        seg[ind] = vec1[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(l, mid, 2 * ind);
    build(mid + 1, r, 2 * ind + 1);
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];
}

void update(long long l, long long r, long long ql, long long qr, long long val, long long ind)
{
    if (l == ql && r == qr)
    {
        seg[ind] += val * (qr - ql + 1);
        lazy[ind] += val;
        return;
    }
    
    // need to go down to child nodes
    push_down(l, r, ind);
    
    long long mid = (l + r) / 2;
    if (qr <= mid) update(l, mid, ql, qr, val, 2 * ind);
    else if (ql > mid) update(mid + 1, r, ql, qr, val, 2 * ind + 1);
    else
    {
        update(l, mid, ql, mid, val, 2 * ind);
        update(mid + 1, r, mid + 1, qr, val, 2 * ind + 1);
    }
    seg[ind] = seg[2 * ind] + seg[2 * ind + 1];

}

long long query(long long l, long long r, long long ql, long long qr, long long ind)
{

    if (l == ql && r == qr) return seg[ind];
    // need to go down to child nodes
    push_down(l, r, ind);
    
    long long mid = (l + r) / 2;
    if (qr <= mid) return query(l, mid, ql, qr, 2 * ind);
    else if (ql > mid) return query(mid + 1, r, ql, qr, 2 * ind + 1);
    else return query(l, mid, ql, mid, 2 * ind) + query(mid + 1, r, mid + 1, qr, 2 * ind + 1);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long m, n, q, type, a, b, c;
    cin >> m >> n >> q;
    seg.resize(4 * n + 2);
    lazy.resize(4 * n + 2);
    vec1.resize(n + 1);
    for (long long i = 1; i <= n; i++) cin >> vec1[i];
    build(1, n, 1);
    for (long long i = 1; i <= q; i++)
    {
        cin >> type;
        if (type == 1)
        {
            cin >> a >> b >> c;
            update(1, n, a, b, c, 1);
        }
        else
        {
            cin >> a >> b;
            cout << (query(1, n, a, b, 1) % m + m)%m << "\n";
        }
    }
}
