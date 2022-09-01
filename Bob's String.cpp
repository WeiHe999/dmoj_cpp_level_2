#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    char a;
    string str1, str2, str3;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        str1 += a;
    }
    while (true)
    {
        str2 = str1;
        reverse(str2.begin(), str2.end());
        if (str1 < str2)
        {
            str3 += str1[0];
            str1 = str1.substr(1);
        }
        else
        {
            str3 += str2[0];
            str1 = str2.substr(1);
        }
        if (str3.size() == n) break;
    }
    cout << str3 << "\n";
}
