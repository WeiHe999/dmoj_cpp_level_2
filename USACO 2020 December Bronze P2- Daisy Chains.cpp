#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, photos = 0, total_petals;
    cin >> n;
    vector <int> petals;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        petals.emplace_back(a);
    }
    bool flag;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            total_petals = 0;
            for (int k = i; k <= j; k++) total_petals += petals[k];
            flag = false;
            for (int k = i; k <= j; k++)
            {
                if (petals[k] * (j - i + 1) == total_petals)
                {
                    flag = true;
                    break;
                }
            }
            if (flag) photos++;
        }
    }
    cout << photos << endl;
}
