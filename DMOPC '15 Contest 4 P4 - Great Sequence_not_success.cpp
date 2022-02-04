#include <bits/stdc++.h>
using namespace std;

bool debug = 0;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, q, z, a, b, c, d;
    bool flag;
    cin >> n >> k >> q;
    vector <int> psa = {0};
    map <int, unordered_set <int> > m1;
    for (int x = 0; x < n; x++)
    {
        cin >> z;
        m1[z].insert(x + 1);
        psa.emplace_back(psa[x] + z);
    }
    if (debug)
    {
        for (auto e : m1)
        {
            cout << e.first << ":  ";
            for (auto f : e.second) cout << f << " ";
            cout << endl;
        }
    }
    for (int y = 0; y < q; y++)
    {
        cin >> a >> b >> c >> d;
        if (psa[d] - psa[c - 1] <= k)
        {
            if (debug) cout << "HHHHHHHH" << endl;
            cout << "No" << endl;
            continue;
        }
        flag = false;
        for (auto e : m1[a])
        {
            if (e >= c && e <= d)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            if (debug) cout << "JJJJJJJJ" << endl;
            cout << "No" << endl;
            continue;
        }
        flag = false;
        for (auto f : m1[b])
        {
            if (f >= c && f <= d)
            {
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            if (debug) cout << "IIIIIIII" << endl;
            cout << "No" << endl;
            continue;
        }
        if (debug) cout << "GGGGGGGG" << endl;
        cout << "Yes" << endl;
    }
}
