#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int y, first = 2;
    cin >> y;
    vector <int> vec1;
    if (y == 1)
    {
        return 0;
    }
    while (true)
    {
        bool flag = true;
        for (int x = first; x * x <= y; x++)
        {
            if (y % x == 0)
            {
                y = y / x;
                vec1.emplace_back(x);
                first = x;
                flag = false;
                break;
            }
        }
        if (flag)
        {
            vec1.emplace_back(y);
            break;
        }
        if (y == 1) break;
    }
    for (auto z : vec1) cout << z << endl;
}
