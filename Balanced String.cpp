#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s;
    getline(cin, s);
    int a = 0, b = 0;
    for (auto c : s)
    {
        if (isalpha(c))
        {
            if (isupper(c)) a++;
            if (islower(c)) b++;
        }
    }
    if (a == b) cout << "YES" << endl;
    else cout << "NO" << endl;
}
