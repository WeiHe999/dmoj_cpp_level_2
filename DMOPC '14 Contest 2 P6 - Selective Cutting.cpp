#include <bits/stdc++.h>
using namespace std;

void update(int ind, int val, vector <int> &bit, int n)
{
    for (int i = ind; i <= n; i += (i & -i)) bit[i] += val;
}

int query(int ind, vector <int> &bit)
{
    int s = 0;
    for (int i = ind; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b, c, ind = 0;
    cin >> n;
    vector <pair <int, int> > vec1;
    vector <int> bit(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        vec1.push_back({a, i});
        //update(i, a, bit, n);
    }
    sort(vec1.rbegin(), vec1.rend());
    cin >> q;
    vector <vector <int> > vec2;
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> b >> c;
        vec2.push_back({c, a + 1, b + 1, i});
    }
    sort(vec2.rbegin(), vec2.rend());
    vector <int> vec3(q + 1);
    for (auto x : vec2)
    {
        int left = x[1], right = x[2];
        while (vec1[ind].first >= x[0])
        {
            update(vec1[ind].second, vec1[ind].first, bit, n);
            ind++;
        }
        vec3[x[3]] = query(right, bit) - query(left - 1, bit);
    }
    for (int i = 1; i <= q; i++) cout << vec3[i] << "\n";
}
