#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, q, a, b, c, s = 0;
    vector <int> vec1(100002);
    cin >> n >> k >> q;
    for (int i = 0; i < q; i++)
    {
        cin >> a >> b >> c;
        vec1[a] += c;
        vec1[b + 1] -= c;
    }
    for (int i = 1; i <= n; i++) vec1[i] += vec1[i - 1];
    for (int i = 1; i <= n; i++) s += vec1[i] < k;
    cout << s << endl;
}
