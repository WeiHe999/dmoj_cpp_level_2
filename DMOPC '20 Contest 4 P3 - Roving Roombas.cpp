#include <bits/stdc++.h>
using namespace std;

vector <long long> bit;

void update(long long i, long long n, long long val)
{
    for (long long ind = i; ind <=n; ind += (ind & -ind)) bit[ind] += val;
}

long long query (long long i)
{
    long long s = 0;
    for (long long ind = i; ind > 0; ind -= (ind & -ind)) s += bit[ind];
    return s;
}

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n, m, a, b, ans = 0;
    cin >> n >> m;
    vector <vector <long long> > vec1;
    bit.resize(n+m+1);
    unordered_map<long long, long long> m1, m2;
    set<long long> s1;
    for (long long i = 1; i <= n; i++)
    {
        cin >> a >> b;
        vec1.push_back({0, 0, b});
        vec1.push_back({a, 2, b});
        s1.insert(b);
    }
    for (long long i = 1; i <= m; i++)
    {
        cin >> a >> b;
        vec1.push_back({a, 1, b});
        s1.insert(b);
    }
    sort(vec1.begin(), vec1.end());
    
    long long id = 1;
    for (auto x: s1)
    {
        m1[x] = id;
        m2[id] = x;
        id++;
    }
    for (auto x : vec1)
    {
        if (x[1] == 0) update(m1[x[2]], n+m, 1);
        else if (x[1] == 1) ans += query(m1[x[2]]);
        else update(m1[x[2]], n+m, -1);
    }
    cout << ans << "\n";
}
