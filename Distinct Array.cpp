#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    unordered_set <int> s1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        s1.insert(a);
    }
    if (s1.size() == n) cout << "YES\n";
    else cout << "NO\n";
}
