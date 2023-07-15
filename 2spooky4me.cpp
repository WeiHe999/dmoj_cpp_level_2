#include <bits/stdc++.h>
using namespace std;
template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}
int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, l, s, a, b, c, cnt = 0;
    cin >> n >> l >> s;
    vector <vector <int> > vec1;
    set <int> s1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c;
        vec1.push_back({a, b, c});
        s1.insert(a);
        s1.insert(b);
        s1.insert(a+1);
        s1.insert(b+1);
    }
    unordered_map <int, int> m1, m2;
    int ind = 1;
    bool flag = true;
    for (auto x : s1)
    {
        if (flag)
        {
            flag = false;
        }
        m1[x] = ind;
        m2[ind] = x;
        ind++;
    }
    vector <int> da(s1.size() + 2), psa(s1.size() + 1);
    for (int i = 0; i < n; i++)
    {
        da[m1[vec1[i][0]]] += vec1[i][2];
        da[m1[vec1[i][1]] + 1] -= vec1[i][2];
    }
    for (int i = 1; i <= s1.size(); i++) psa[i] = psa[i - 1] + da[i];
    //print(psa);
    int start_pos = -1, end_pos;
    for (int i = 1; i <= s1.size(); i++)
    {
        if (psa[i] >= s)
        {
            if (start_pos == -1) start_pos = m2[i];
        }
        else if (start_pos != -1)
        {
            cnt += m2[i - 1] - start_pos + 1;
            start_pos = -1;
        }
    }
    if (start_pos != -1)
    {
        cnt += m2[s1.size()] - start_pos + 1;
    }
    cout << l - cnt << "\n";
}
