#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MM = 2e7;
int num = 1; // global index
vector<int> seg_sum(MM), seg_max(MM), lc_ind(MM), rc_ind(MM);

void update(int l, int r, int pos, int val, int ind)
{
    if (l == pos && r == pos)
    {
        seg_sum[ind] = val;
        seg_max[ind] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) 
    {
        // create a left child if not exist
        if(!lc_ind[ind])
        {
            num++;
            lc_ind[ind] = num;
        }
        update(l, mid, pos, val, lc_ind[ind]);
    }
    else 
    {
        // create a right child
        if(!rc_ind[ind])
        {
            num++;
            rc_ind[ind] = num;        
        }
        update(mid + 1, r, pos, val, rc_ind[ind]);
    }
    seg_sum[ind] = seg_sum[lc_ind[ind]] + seg_sum[rc_ind[ind]];
    seg_max[ind] = max(seg_max[lc_ind[ind]], seg_max[rc_ind[ind]]);
}

int query_sum(int l, int r, int ql, int qr, int ind)
{
    if (l == ql && r == qr) return seg_sum[ind];
    int mid = (l + r) / 2;
    if (qr <= mid) return query_sum(l, mid, ql, qr, lc_ind[ind]);
    else if (ql > mid) return query_sum(mid + 1, r, ql, qr, rc_ind[ind]);
    else return query_sum(l, mid, ql, mid, lc_ind[ind]) + query_sum(mid + 1, r, mid + 1, qr, rc_ind[ind]);
}

int query_max(int l, int r, int ql, int qr, int ind)
{
    if (l == ql && r == qr) return seg_max[ind];
    int mid = (l + r) / 2;
    if (qr <= mid) return query_max(l, mid, ql, qr,  lc_ind[ind]);
    else if (ql > mid) return query_max(mid + 1, r, ql, qr, rc_ind[ind]);
    else return max(query_max(l, mid, ql, mid,  lc_ind[ind]), query_max(mid + 1, r, mid + 1, qr, rc_ind[ind]));
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b, last = 0;
    cin >> n >> q;
    char c;
    for (int i = 1; i <= q; i++)
    {
        cin >> c >> a >> b;
        a ^= last;
        b ^= last;
        if (c == 'C') update(1, n, a, b, 1);
        else if (c == 'S')
        {
            last = query_sum(1, n, a, b, 1);
            cout << last << "\n";
        }
        else
        {
            last = query_max(1, n, a, b, 1);
            cout << last << "\n";
        }
    }
}
