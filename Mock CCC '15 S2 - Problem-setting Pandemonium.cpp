#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    map <int, int> m1, m2;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        m1[a]++;
    }
    for (auto x : m1) m2[x.second] = x.first;
    cout << (*m2.rbegin()).first << "\n";
}
