#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int y, i, j, d;
    char c;
    string s;
    getline(cin, s);
    map <char, vector <int> > m1;
    for (int x = 0; x < s.size(); x++) if (s[x] != ' ') m1[s[x]].emplace_back(x);
    cin >> y;
    for (int a = 0; a < y; a++)
    {
        cin >> i >> j >> c;
        d = 0;
        for (auto b : m1[c])
        {
            if (b + 1 > j) break;
            if (b + 1 >= i) d++;
        }
        cout << d << endl;
    }
}
