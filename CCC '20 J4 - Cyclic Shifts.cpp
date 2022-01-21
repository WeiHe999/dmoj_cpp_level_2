#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string t, s, ans = "no";
    getline(cin, t);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
    {
        if (t.find(s) != -1)
        {
            ans = "yes";
            break;
        }
        s = s[s.size() - 1] + s.substr(0, s.size() - 1);
    }
    cout << ans << endl;
}
