#include <bits/stdc++.h>
using namespace std;

int check_fix(string str1, string str2)
{
    if (str2.length() < str1.length())
    {
        if (str1.substr(0, str2.length()) == str2 || str1.substr(str1.length() - str2.length()) == str2)
        {
            return 1;
        }
    }
    if (str1.length() < str2.length())
    {
        if (str2.substr(0, str1.length()) == str1 || str2.substr(str2.length() - str1.length()) == str1)
        {
            return 1;
        }
    }
    if (str1 == str2)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    int n;
    cin >> n;
    cin.ignore();
    for (int x = 0; x < n; x++)
    {
        string str1, str2, str3;
        getline(cin, str1);
        getline(cin, str2);
        getline(cin, str3);
        if (check_fix(str1, str2) == 1) cout << "No" << endl;
        else if (check_fix(str1, str3) == 1) cout << "No" << endl;
        else if (check_fix(str2, str1) == 1) cout << "No" << endl;
        else if (check_fix(str2, str3) == 1) cout << "No" << endl;
        else if (check_fix(str3, str1) == 1) cout << "No" << endl;
        else if (check_fix(str3, str2) == 1) cout << "No" << endl;
        else cout << "Yes" << endl;
    }
}
