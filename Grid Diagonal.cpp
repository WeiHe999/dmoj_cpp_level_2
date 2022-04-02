#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string str1, str2, str3;
    cin >> str1 >> str2 >> str3;
    cout << str1[0] << str2[1] << str3[2] << endl;
    cout << str1[2] << str2[1] << str3[0] << endl;
}
