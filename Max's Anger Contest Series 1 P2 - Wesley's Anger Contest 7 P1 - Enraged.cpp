#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    vector <char> vec1(n), vec2(n);
    for (int x = 0; x < n; x++) cin >> vec1[x];
    for (int x = 0; x < n; x++) cin >> vec2[x];
    if (vec2[n - 1] == 'S')
    {
        cout << "NO\n";
        return 0;
    }
    for (int x = 0; x < n; x++) if (vec1[x] == 'S' && vec2[x] == 'S') s++;
    if (s <= 2) cout << "YES\n";
    else cout << "NO\n";
}
