#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int r, c, n, s = 0;
    cin >> c >> r >> n;
    vector <vector <int> > psa(r + 1, vector <int>(c + 1));
    for (int i = 1; i <= r; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> psa[i][j];
            psa[i][j] += psa[i - 1][j] + psa[i][j - 1] - psa[i - 1][j - 1];
        }
    }
    for (int x = 1; x <= r; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            for (int side1 = 1; side1 <= r - x + 1; side1++)
            {
                int side2 = min(n / side1, c - y + 1);
                if (side2 == 0) continue;
                s = max(psa[x + side1 - 1][y + side2 - 1] - psa[x + side1 - 1][y - 1] - psa[x - 1][y + side2 - 1] + psa[x - 1][y - 1], s);
            }
        }
    }
    cout << s << "\n";
}
