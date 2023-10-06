#include <bits/stdc++.h>
using namespace std;

int MM = 1e9 + 7;
//int bit[2005][2005];
vector <vector <int> > bit(3011, vector <int>(3011));

void update(int r, int c, int val)
{
    for (int i = c; i <= r + c; i += (i & -i)) bit[r + c][i] = (bit[r + c][i] + val) % MM;
}

int query(int r, int c)
{
    int s = 0;
    for (int i = c; i > 0; i -= (i & -i)) 
    {
        s = (s + bit[r + c][i]) % MM;
        //s %= MM;
    }
    return s;
}

int query(int r, int c, int x)
{
    return (query(r - x, c + x) - query(r + 1, c - 1) + MM) % MM;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, r, c, x, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> r >> c >> x;
        if (t == 1) update(r, c, x);
        if (t == 2) 
        {
            s += (query(r - x, c + x) - query(r + 1, c - 1) + MM) % MM;
            s %= MM;
        }
    }
    cout << s << "\n";
}
