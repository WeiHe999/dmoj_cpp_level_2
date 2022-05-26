#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1;
    cin >> str1;
    int s = 0;
    for (int x = 0; x < str1.size(); x++)
    {
        if (str1[x] == '2')
        {
            if (str1[x + 1] == '5') x++;
            else s++;
        }
    }
    cout << s << "\n";
}
