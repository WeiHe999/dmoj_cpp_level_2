#include <bits/stdc++.h>
using namespace std;

int main ()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, b;
    cin >> n;
    vector <int> vec1, vec2;
    for (int y = 0; y < pow(2, n); y++)
    {
        cin >> b;
        vec2.emplace_back(b);
        vec1.emplace_back(b);
    }
    sort(vec1.begin(), vec1.end());
    for (int i = 0; i < pow(2, n); i++)
    {
        int x = vec1.end() - upper_bound(vec1.begin(), vec1.end(), vec2[i]);
        if (x == 0)
        {
            cout << 0 << " ";
            continue;
        }
        bool flag = false;
        for (int z = n - 1; z >= 0; z--)
        {
            if (pow(2, z) < x) x -= pow(2, z);
            else
            {
                cout << n - z << " ";
                flag = true;
                break;
            }
        }
        if (!flag) cout << n << " ";
    }
}
