#include <bits/stdc++.h>
using namespace std;

int MM = 15001;
vector <int> bit(MM * 2);

void update(int ind)
{
    ind += MM;
    for (int i = ind; i < bit.size(); i += (i & -i)) bit[i]++;
}

int query(int ind)
{
    ind += MM;
    int s = 0;
    for (int i = ind; i > 0; i -= (i & -i)) s += bit[i];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    long long s = 0, ind = 0;
    cin >> n;
    update(ind);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        if (a == 2) ind--;
        else ind++;
        s += query(ind - 1); 
        update(ind);
    }
    cout << s << "\n";
}
