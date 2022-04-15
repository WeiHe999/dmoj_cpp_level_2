#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, x, y;
    cin >> n >> k;
    unordered_map <int, int> row, col, dl, dr;
    for (int a = 0; a < n; a++)
    {
        cin >> x >> y;
        row[x]++;
        if (row[x] == k)
        {
            cout << a + 1 << endl;
            return 0;
        }
        col[y]++;
        if (col[y] == k)
        {
            cout << a + 1 << endl;
            return 0;
        }
        dl[x + n - 1 - y]++;
        if (dl[x + n - 1 - y] == k)
        {
            cout << a + 1 << endl;
            return 0;
        }
        dr[2 * n - 2 - x - y]++;
        if (dr[2 * n - 2 - x - y] == k)
        {
            cout << a + 1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
