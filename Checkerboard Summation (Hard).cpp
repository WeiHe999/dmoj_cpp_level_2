#include <bits/stdc++.h>
using namespace std;


void update(long long r, long long c, long long val, vector <vector <long long> > &bit, long long m, long long n)
{
    for (long long i = r; i <= m; i += (i & -i)) for (long long j = c; j <= n; j += (j & -j)) bit[i][j] += val;
}

long long query(long long r, long long c, vector <vector <long long> > &bit)
{
    long long s = 0;
    for (long long i = r; i >= 1; i -= (i & -i)) for (long long j = c; j >= 1; j -= (j & -j)) s += bit[i][j];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long m, n, op, r, c, x, y, s1, s2;
    cin >> m >> n;
    vector <vector <long long> > bit1(m + 1, vector <long long>(n + 1)), grid1(m + 1, vector <long long>(n + 1));//odd
    vector <vector <long long> > bit2(m + 1, vector <long long>(n + 1)), grid2(m + 1, vector <long long>(n + 1));//even
    while (true)
    {
        cin >> op;
        if (op == 0) break;
        if (op == 1)
        {
            cin >> r >> c >> x;
            if ((r+c)%2==1)
            {
                update(r, c, x - grid1[r][c], bit1, m, n);
                grid1[r][c] = x;
            }
            else
            {
                update(r, c, x - grid2[r][c], bit2, m, n);
                grid2[r][c] = x;               
            }
            
        }
        if (op == 2)
        {
            cin >> r >> c >> x >> y;
            s1 = query(x, y, bit1) - query(r - 1, y, bit1) - query(x, c - 1, bit1) + query(r - 1, c - 1, bit1);
            s2 = query(x, y, bit2) - query(r - 1, y, bit2) - query(x, c - 1, bit2) + query(r - 1, c - 1, bit2);
            cout << int(pow(-1, r + c) * (s2-s1)) << "\n";
        }
    }
    
    //for (auto x: grid) prlong long(x);
    
}
