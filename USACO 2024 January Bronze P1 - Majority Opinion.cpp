#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, n;
    cin >> t;
    for (int x = 1; x <= t; x++)
    {
        cin >> n;
        vector <int> vec1(n);
        vector <bool> check(n, false);
        for (int i = 0; i < n; i++)
        {
            cin >> vec1[i];
            vec1[i]--;
            if (i > 0 && vec1[i] == vec1[i - 1] || i > 1 && vec1[i] == vec1[i - 2]) check[vec1[i]] = true;
        }
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (check[i])
            {
                flag = true;
                cout << i + 1 << " ";
            }
        }
        if (!flag) cout << "-1\n";
        else cout << "\n";
    }
}
