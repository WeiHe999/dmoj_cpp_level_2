#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    int n = str1.size() / 2, flag1 = 2, flag2 = 2;
    if (str1.size() % 2 == 0)
    {
        cout << "NOT POSSIBLE\n";
        return 0;
    }
    char c = str1[0];
    bool flag = true;
    for (auto x : str1)
    {
        if (x != c)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << str1.substr(0, n) << "\n";
        return 0;
    }
    for (int i = 0, j = n + 1; i <= n; i++)
    {
        if (str1[i] != str1[j])
        {
            flag1--;
            if (flag1 == 0) break;
        }
        else j++;
    }
    for (int i = 0, j = n; j <= 2 * n; j++)
    {
        if (str1[i] != str1[j])
        {
            flag2--;
            if (flag2 == 0) break;
        }
        else i++;
    }
    if (flag1 == 0 && flag2 == 0) cout << "NOT POSSIBLE\n";
    else if (flag1 == 2 || flag2 == 2) cout << "NOT UNIQUE\n";
    else if (flag1 == 1) cout << str1.substr(n + 1) << "\n";
    else cout << str1.substr(0, n) << "\n";
}
