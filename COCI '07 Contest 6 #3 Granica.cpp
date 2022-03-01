#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, a, mina = INT_MAX;
    vector <int> vec1, vec2;
    unordered_set<int> s1;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (auto b : vec1)
    {
        for (auto c : vec1)
        {
            if (c != b)
            {
                vec2.emplace_back(abs(c - b));
                mina = min(abs(c - b), mina);
            }
        }
    }
    for (int d = 1; d * d <= mina; d++)
    {
        if (mina % d != 0) continue;
        int m1 = d, m2 = mina / d;
        bool flag1 = false, flag2 = false;
        for (int e = 0; e < vec2.size(); e++)
        {
            if (vec2[e] % m1 != 0) flag1 = true;
            if (vec2[e] % m2 != 0) flag2 = true;
        }
        if (!flag1 && m1 != 1 && m1 != m2) s1.insert(m1);
        if (!flag2) s1.insert(m2);
    }
    int ind = 0;
    for (auto x: s1)
    {
        if (ind==s1.size()-1)
        {
            cout << x;
        }
        else cout << x << " ";
        ind++;
    }
    cout << endl;
}
