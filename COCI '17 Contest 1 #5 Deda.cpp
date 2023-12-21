#include <bits/stdc++.h>
using namespace std;

int search(int b, int a, int x, int l, int r, int k, vector <int> &tournament)
{
    if (x >= k)
    {
        return l;
    }
    int mid = (l + r) / 2;
    if (mid > b && tournament[x * 2] <= a)
    {
        int s = search(b, a, x * 2, l, mid, k, tournament);
        if (s != 1e9) return s;
    }
    if (tournament[x * 2 + 1] > a) return 1e9;
    return search(b, a, x * 2 + 1, mid, r, k, tournament);
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, k = 1, a, b;
    cin >> n >> q;
    vector <int> tournament(600000);
    while (k < n) k *= 2;
    for (int i = 1; i < 2 * k; i++) tournament[i] = 1e9;
    char c;
    for (int i = 0; i < q; i++)
    {
        cin >> c >> a >> b;
        b--;
        if (c == 'M') for (int j = k + b; j > 0; j /= 2) tournament[j] = min(tournament[j], a);
        else
        {
            int s = search(b, a, 1, 0, k, k, tournament);
            if (s == 1e9) cout << "-1\n";
            else cout << s + 1 << "\n";
        }
    }
}
