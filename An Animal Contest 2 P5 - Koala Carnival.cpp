#include <bits/stdc++.h>
using namespace std;

int query(int l, int r, vector <vector <int> > &st)
{
    int k = log2(r - l + 1);
    return max(st[l][k], st[r - (1 << k) + 1][k]);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, l = 1, s = 0, r;
    cin >> n >> q;
    vector <int> vec1(n + 1), vec2;
    vector <vector <int> > st(n + 1, vector <int>(log2(n) + 1));
    unordered_map <int, int> m1;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        m1[vec1[i]]++;
        while (m1[vec1[i]] > 1)
        {
            m1[vec1[l]]--;
            l++;
        }
        st[i][0] = i - l + 1;
        vec2.push_back(l);
    }
    vec2.push_back(n + 1);
    for (int k = 1; (1 << k) <= n; k++)
    {
        for (int i = 1; i + (1 << k - 1) <= n; i++) st[i][k] = max(st[i][k - 1], st[i + (1 << k - 1)][k - 1]);
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> l >> r;
        l ^= s;
        r ^= s;
        s = query(r, upper_bound(vec2.begin(), vec2.end(), l) - vec2.begin(), st);
        cout << s << "\n";
    }
}
