#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    bool flag;
    unordered_set <char> s1 = {'a', 'e', 'i', 'o', 'u'};
    if (str1.size() == 0)
    {
        cout << "YES\n";
        return 0;
    }
    if (s1.count(str1[0]))
    {
        flag = true;
        for (int i = 1; i < str1.size(); i += 2)
        {
            if (i == str1.size() - 1)
            {
                if (s1.count(str1[i])) flag = false;
                continue;
            }
            if (s1.count(str1[i]) || !s1.count(str1[i + 1]))
            {
                flag = false;
                break;
            }
        }
    }
    else
    {
        flag = true;
        for (int i = 1; i < str1.size(); i += 2)
        {
            if (i == str1.size() - 1)
            {
                if (!s1.count(str1[i])) flag = false;
                continue;
            }
            if (!s1.count(str1[i]) || s1.count(str1[i + 1]))
            {
                flag = false;
                break;
            }
        }
    }
    if (flag) cout << "YES\n";
    else cout << "NO\n";
}
