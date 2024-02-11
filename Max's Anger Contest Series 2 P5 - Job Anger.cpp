#include <bits/stdc++.h>
using namespace std;
#define int long long

vector <int> bit;

void update(int i, int n, int val)
{
    for (i; i <= n; i += (i & -i)) bit[i] += val;
}

int query(int i)
{
    int s = 0;
    for (i; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, c, d, s = 0;
    cin >> n;
    bit.resize(2 * n + 1);
    vector <vector <int> > events;
    set <int> s1;
    unordered_map <int, int> m1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        s1.insert(b);
        s1.insert(d);
        if (a == c)
        {
            events.push_back({a, 1, b, d});
        }
        else
        {
            events.push_back({a, 0, b, i});
            events.push_back({c, 2, d, i});
        }
    }
    int ind = 1;
    for (auto x : s1)
    {
        m1[x] = ind;
        ind++;
    }
    sort(events.begin(), events.end());
    for (auto x : events)
    {
        if (x[1] == 0) update(m1[x[2]], 2 * n, 1);
        else if (x[1] == 1) s += query(m1[x[3]]) - query(m1[x[2]] - 1);
        else update(m1[x[2]], 2 * n, -1);
    }
    cout << s << "\n";
}
