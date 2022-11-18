#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    while (true)
    {
        n++;
        string a = to_string(n);
        bool flag = true;
        for (int x = 0; x < a.size(); x++)
        {
            for (int y = x + 1; y < a.size(); y++)
            {
                if (a[x] == a[y])
                {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) break;
    }
    cout << n << "\n";
}
