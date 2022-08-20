#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    vector <int> vec1(10001);
    for (int x = 2; x < 10001; x++)
    {
        if (vec1[x] == 0)
        {
            for (int y = x * 2; y < 10001; y += x)
            {
                vec1[y]++;
            }
        }
    }
    for (int x = 0; x < 5; x++)
    {
        bool flag = true;
        unordered_map <int, int> m1;
        int a;
        cin >> a;
        for (int y = 2; y <= a; y++)
        {
            if (vec1[y] == 0)
            {
                for (int current = y; current <= a; current *= y)
                {
                    m1[y] += a / current;
                }
                if (!flag) cout << " * " << y << "^" << m1[y];
                else cout << y << "^" << m1[y];
                flag = false;
            }
        }
        cout << "\n";
    }
}
