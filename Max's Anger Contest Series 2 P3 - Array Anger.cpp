#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, l, s;
    cin >> n >> q;
    vector <int> vec1(n + 1), psa(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        psa[i] = psa[i - 1] + vec1[i];
    }
    string a;
    for (int i = 1; i <= q; i++)
    {
        cin >> a >> l >> s;
        cout << min(int(lower_bound(psa.begin(), psa.end(), s + psa[l - 1]) - psa.begin()), n) << "\n";
    }
}
