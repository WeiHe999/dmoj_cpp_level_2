#include <bits/stdc++.h>
using namespace std;

void update(long long ind, long long val, vector <long long> &bit, long long n)
{
    for (long long i = ind; i <= n; i += (i & -i)) bit[i] += val;
}

long long query(long long ind, vector <long long> &bit)
{
    long long s = 0;
    for (long long i = ind; i >= 1; i -= (i & -i)) s += bit[i];
    return s;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, q, l, r, k;
    cin >> n >> q;
    vector <long long> vec1(n + 1);
    vector <vector <long long> > vec2;
    vector <pair <long long, long long> > vec3;
    vector <long long> bit1(n + 1), bit2(n + 1);
    unordered_map <long long, long long> m1;
    for (long long i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        vec3.push_back({vec1[i], i});
        update(i, vec1[i], bit1, n);
        update(i, vec1[i], bit2, n);
    }
    for (long long i = 1; i <= q; i++)
    {
        cin >> l >> r >> k;
        vec2.push_back({k, l, r, i});
    }
    sort(vec2.rbegin(), vec2.rend());
    sort(vec3.rbegin(), vec3.rend());
    long long ptr = 0;
    for (long long i = 0; i < vec2.size(); i++)
    {
        long long left = vec2[i][1], right = vec2[i][2], kk = vec2[i][0];
        while (vec3[ptr].first >= kk)
        {
            update(vec3[ptr].second, -vec3[ptr].first, bit2, n);
            ptr++;
        }
        m1[vec2[i][3]] = (query(right, bit1) - query(left - 1, bit1)) - (2 * (query(right, bit2) - query(left - 1, bit2)));
    }
    for (long long i = 1; i <= q; i++) cout << m1[i] << "\n";
}
