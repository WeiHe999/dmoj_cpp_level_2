#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, sum = 0, s = 0, a, b;
    string str1;
    cin >> n;
    vector <int> vec1(n + 1);
    unordered_map <int, int> m1;
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        m1[vec1[i]]++;
        sum += vec1[i];
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> str1;
        if (str1 == "INFLATION")
        {
            cin >> a;
            s += a;
        }
        else
        {
            cin >> a >> b;
            if (a == b)
            {
                cout << sum + s * n << "\n";
                continue;
            }
            sum += m1[a - s] * (b - a);
            m1[b - s] += m1[a - s];
            m1[a - s] = 0;
        }
        cout << sum + s * n << "\n";
    }
}
