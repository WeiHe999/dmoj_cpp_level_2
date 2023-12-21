#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> seg, vec1;
vector <pair <int, int> > vec2;

int update(int l, int r, int pos, int val, int ind)
{
    if (pos == l && pos == r)
    {
        seg[ind] = val;
        return seg[ind];
    }
    if (pos < l || pos > r) return seg[ind];
    int mid = (l + r) / 2;
    seg[ind] = min(update(l, mid, pos, val, ind + 1), update(mid + 1, r, pos, val, ind + (mid - l + 1) * 2));
    return seg[ind];
}

int removed(int l, int r, int ql, int qr, int ind)
{
    if (ql > r || qr < l) return seg[ind];
    if (ql <= l && r <= qr)
    {
        if (seg[ind] != 1e18)
        {
            vec2.push_back({ind, seg[ind]});
            seg[ind] = 1e18;
        }
        return seg[ind];
    }
    int mid = (l + r) / 2, tmp = min(removed(l, mid, ql, qr, ind + 1), removed(mid + 1, r, ql, qr, ind + (mid - l + 1) * 2));
    if (seg[ind] != tmp)
    {
        vec2.push_back({ind, seg[ind]});
        seg[ind] = tmp;
    }
    return seg[ind];
}

int query(int l, int r, int ind, int k)
{
    if (l == r)
    {
        if (seg[ind] < k) return l;
        return 1e18;
    }
    int mid = (l + r) / 2;
    if (seg[ind + 1] < k) return query(l, mid, ind + 1, k);
    return query(mid + 1, r, ind + (mid - l + 1) * 2, k);
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, last_ans = 0, t, a, b, c;
    cin >> n >> q;
    seg.resize(4 * n + 2, 0x3f);
    vec1.resize(n + 1);
    for (auto i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        update(1, n, i, vec1[i], 1);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> a >> b;
            a ^= last_ans;
            b ^= last_ans;
            update(1, n, a, b, 1);
        }
        else
        { 
            cin >> a >> b >> c;
            a ^= last_ans;
            b ^= last_ans;
            c ^= last_ans;
            removed(1, n, 1, a - 1, 1);
            last_ans = query(1, n, 1, c);
            cout << last_ans << "\n";
            for (auto x : vec2) seg[x.first] = x.second;
            vec2 = {};
        }
    }
}
