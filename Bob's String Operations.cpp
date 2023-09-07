#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2;
    cin >> str1 >> str2;
    unordered_map <char, char> m1, m2;
    for (int i = 0; i < str1.size(); i++)
    {
        if ((m1.count(str1[i]) && m1[str1[i]] != str2[i]) || (m2.count(str2[i]) && m2[str2[i]] != str1[i]))
        {
            cout << "No\n";
            return 0;
        }
        else
        {
            m1[str1[i]] = str2[i];
            m2[str2[i]] = str1[i];
        }
    }
    cout << "Yes\n";
}
