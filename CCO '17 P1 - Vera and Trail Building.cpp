#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, v = 0, e;
    cin >> n;
    vector <int> vec1;
    while (n)
    {
        a = int(sqrt(n * 2));
        if (a * (a + 1) / 2 > n) b = a * (a - 1) / 2;
        else
        {
            b = a * (a + 1) / 2;
            a++;
        }
        vec1.emplace_back(a);
        n -= b;
    }
    for (auto f : vec1) v += f;
    e = v + vec1.size() - 1;
    cout << v << " " << e << "\n";
    int d = 1, tmp;
    for (int c = 0; c < vec1.size(); c++)
    {
        tmp = d;
        for (d; d < tmp + vec1[c] - 1;)
        {
            cout << d << " " << d + 1 << "\n";
            d++;
        }
        cout << tmp + vec1[c] - 1 << " " << tmp << "\n";
        if (c < vec1.size() - 1) cout << tmp + vec1[c] - 1 << " " << tmp + vec1[c] << "\n";
        d++;
    }
}
