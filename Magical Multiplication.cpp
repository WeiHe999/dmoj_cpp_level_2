#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2;
    cin >> str1 >> str2;
    int s = 0;
    for (auto x : str1) for (auto y : str2) s += (x - '0') * (y - '0');
    cout << s << "\n";
}
