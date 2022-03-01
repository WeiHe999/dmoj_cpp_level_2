#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str1, substr1;
    cin >> str1;
    bool flag = false;
    for (long long a = 0; a < str1.size(); a++)
    {
        if (isdigit(str1[a]))
        {
            cout << str1[a];
            flag = true;
            continue;
        }
        if (str1[a] == '+')
        {
            cout << substr1 << " tighten ";
            substr1 = "";
        }
        else if (str1[a] == '-')
        {
            cout << substr1 << " loosen ";
            substr1 = "";
        }
        else
        {
            if (flag) cout << endl;
            flag = false;
            substr1 += str1[a];
        }
    }
}
