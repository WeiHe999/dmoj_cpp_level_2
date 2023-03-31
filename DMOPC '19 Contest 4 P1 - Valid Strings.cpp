#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string str1, str2;
        cin >> str1;
        stack <int> s1;
        bool flag = true;
        for (int j = 0; j < str1.size(); j++)
        {
            if (str1[j] == '(') s1.push(str1[j]);
            else if (str1[j] == ')' && s1.empty())
            {
                flag = false;
                break;
            }
            else if (str1[j] == ')') s1.pop();
            else str2 += str1[j];
        }
        for (auto x : str2)
        {
            if (!isdigit(x))
            {
                flag = false;
                break;
            }
        }
        if (s1.empty() && flag) cout << "YES\n";
        else cout << "NO\n";
    }
}
