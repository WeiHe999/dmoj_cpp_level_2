#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}

int MM = 1e8+3;

void update(int ind, int val, vector <int> &bit)
{
    for (int i = ind; i <= MM; i += (i & -i)) bit[i] += val;
}

int query(int ind, vector <int> &bit)
{
    int s = 0;
    for (int i = ind; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int binary_search(int k, vector <int> &bit)
{
    int left = 1, right = MM, m, ans;
    while (left <= right)
    {
        m = (left + right) / 2;
        if (query(m, bit) < k) left = m + 1;
        else
        {
            right = m - 1;
            ans = m;
        }
    }
    return ans;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, x, r, num = 0;
    cin >> n;
    char c;
    unordered_map <int, int> m1, m2;
    vector <int> bit(MM);
    for (int i = 1; i <= n; i++)
    {
        cin >> c;
        if (c == 'N')
        {
            cin >> x >> r;
            update(r, 1, bit);
            m1[r] = x;
            m2[x] = r;
            num++;
        }
        if (c == 'M')
        {
            cin >> x >> r;
            update(m2[x], -1, bit);
            update(r, 1, bit);
            m1[r] = x;
            m2[x] = r;
        }
        if (c == 'Q')
        {
            cin >> x;
            int f = binary_search(num - x + 1, bit);
            cout << m1[f] << "\n";
        }
    }
}
