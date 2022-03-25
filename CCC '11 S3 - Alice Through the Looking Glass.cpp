#include <bits/stdc++.h>
using namespace std;

bool examine(int m, int x, int y, vector <int> vec1)
{
    if (m == 1)
    {
        if (y == 0 && (x == 1 || x == 2 || x == 3)) return 1;
        if (y == 1 && x == 2) return 1;
        return 0;
    }
    if ((x < vec1[m] / 5)||(x >= 4 * vec1[m] / 5)) return 0;
    if (x >= vec1[m] / 5 && x < 2 * vec1[m] / 5)
    {
        if (y < vec1[m] / 5) return 1;
        if (y >= vec1[m] / 5 && y < 2 * vec1[m] / 5) return examine(m - 1, x - vec1[m] / 5, y - vec1[m] / 5, vec1);
        return 0;
    }
    if (x >= 2 * vec1[m] / 5 && x < 3 * vec1[m] / 5)
    {
        if (y < 2 * vec1[m] / 5) return 1;
        if (y >= 2 * vec1[m] / 5 && y < 3 * vec1[m] / 5) return examine(m - 1, x - 2 * vec1[m] / 5, y - 2 * vec1[m] / 5, vec1);
        return 0;
    }
    if (x >= 3 * vec1[m] / 5 && x < 4 * vec1[m] / 5)
    {
        if (y < vec1[m] / 5) return 1;
        if (y >= vec1[m] / 5 && y < 2 * vec1[m] / 5) return examine(m - 1, x - 3 * vec1[m] / 5, y - vec1[m] / 5, vec1);
        return 0;
    }
}
int main()
{
    int t, m, x, y;
    cin >> t;
    vector <int> vec1 = {1};
    for (int i = 1; i < 14; i++) vec1.emplace_back(5 * vec1[i - 1]);
    for (int a = 0; a < t; a++)
    {
        cin >> m >> x >> y;
        if (examine(m, x, y, vec1)) cout << "crystal" << endl;
        else cout << "empty" << endl;
    }
}
