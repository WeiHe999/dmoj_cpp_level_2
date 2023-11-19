#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}
int MM = 100000;
vector <vector <int> > seg(4*MM + 1, vector <int>(5));
vector <int> vec1(MM+1);

void build(int l, int r, int ind)
{
    seg[ind][0] = l;
    seg[ind][1] = r;
    if (l == r)
    {
        seg[ind][2] = vec1[l];
        seg[ind][3] = vec1[l];
        seg[ind][4] = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(l, mid, 2 * ind);
    build(mid + 1, r, 2 * ind + 1);
    seg[ind][2] = min(seg[2 * ind][2], seg[2 * ind + 1][2]);
    seg[ind][3] = __gcd(seg[2 * ind][3], seg[2 * ind + 1][3]);
    if (seg[ind][3] == seg[2 * ind][3]) seg[ind][4] += seg[2 * ind][4];
    else for (int i = l; i <= mid; i++) if (vec1[i] == seg[ind][3]) seg[ind][4]++;
    if (seg[ind][3] == seg[2 * ind + 1][3]) seg[ind][4] += seg[2 * ind + 1][4];
    else for (int i = mid + 1; i <= r; i++) if (vec1[i] == seg[ind][3]) seg[ind][4]++;
}

void update(int pos, int val, int ind)
{
    if (seg[ind][0] == pos && seg[ind][1] == pos)
    {
        seg[ind][2] = val;
        seg[ind][3] = val;
        seg[ind][4] = 1;
        return;
    }
    int mid = (seg[ind][0] + seg[ind][1]) / 2;
    if (pos <= mid) update(pos, val, 2 * ind);
    else update(pos, val, 2 * ind + 1);
    seg[ind][2] = min(seg[2 * ind][2], seg[2 * ind + 1][2]);
    seg[ind][3] = __gcd(seg[2 * ind][3], seg[2 * ind + 1][3]);
    seg[ind][4] = 0;
   
    if (seg[ind][3] == seg[2 * ind][3]) 
    {
        //cout << "seg[2 * ind][3]=" << seg[2 * ind][3] << endl;
        seg[ind][4] += seg[2 * ind][4];
    }
    else for (int i = seg[ind][0]; i <= mid; i++) if (vec1[i] == seg[ind][3]) seg[ind][4]++;
    if (seg[ind][3] == seg[2 * ind + 1][3]) 
    {
        //cout << "seg[seg[2 * ind + 1][3]=" << seg[2 * ind + 1][3] << endl;
        seg[ind][4] += seg[2 * ind + 1][4];
    }
    else for (int i = mid + 1; i <= seg[ind][1]; i++) if (vec1[i] == seg[ind][3]) seg[ind][4]++;
}

int query(int l, int r, int ind, char c)
{
    if (seg[ind][0] == l && seg[ind][1] == r)
    {
        if (c == 'M') return seg[ind][2];
        else return seg[ind][3];
    }
    int mid = (seg[ind][0] + seg[ind][1]) / 2;
    if (r <= mid) return query(l, r, 2 * ind, c);
    else if (l > mid) return query(l, r, 2 * ind + 1, c);
    else
    {
        if (c == 'M') return min(query(l, mid, 2 * ind, c), query(mid + 1, r, 2 * ind + 1, c));
        else return __gcd(query(l, mid, 2 * ind, c), query(mid + 1, r, 2 * ind + 1, c));
    }
}

pair <int, int> query2(int l, int r, int ind)
{
    if (seg[ind][0] == l && seg[ind][1] == r) return {seg[ind][3], seg[ind][4]};
    int mid = (seg[ind][0] + seg[ind][1]) / 2;
    if (r <= mid) return query2(l, r, 2 * ind);
    else if (l > mid) return query2(l, r, 2 * ind + 1);
    else
    {
        pair <int, int> tmp1 = query2(l, mid, 2 * ind), tmp2 = query2(mid + 1, r, 2 * ind + 1);
        int ans = 0, gcd = __gcd(tmp1.first, tmp2.first);
        if (gcd == tmp1.first) 
        {
            ans += tmp1.second;
        }
        if (gcd == tmp2.first) 
        {
            ans += tmp2.second;
        }
        return {gcd, ans};
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    build(1, n, 1);
 
    
    char c;
    for (int i = 1; i <= m; i++)
    {
        cin >> c >> a >> b;
        if (c == 'C') 
        {
            vec1[a] = b;
            update(a, b, 1);
           
        }
        else if (c == 'Q') 
        {
            
            cout << query2(a, b, 1).second << "\n";
        }
        else 
        {
            cout << query(a, b, 1, c) << "\n";
        }
    }
}
