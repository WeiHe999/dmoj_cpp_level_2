#include <bits/stdc++.h>
using namespace std;

void indent(int level)
{
    for (int x = 0; x < level; x++) cout << "  ";
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s;
    cin >> s;
    int level = 0;
    bool new_line = true;
    for (int x = 0; x < s.size(); x++)
    {
        if (new_line) indent(level);
        if (s[x] == '{')
        {
            cout << "{" << endl;
            level++;
            if (s[x + 1] == '}')
            {
                new_line = true;
                level--;
            }
            else
            {
                new_line = true;
            }
        }
        else if (s[x] == '}')
        {
            cout << "}";
            if (s[x + 1] == ',')
            {
                new_line = false;
            }
            else
            {
                level--;
                new_line = true;
                cout << endl;
            }
        }
        else if (s[x] == ',')
        {
            cout << "," << endl;
            new_line = true;
        }
        else
        {
            cout << s[x];
            if (s[x + 1] == '}')
            {
                level--;
                new_line = true;
                cout << endl;
            }
            else
            {
                new_line = false;
            }
        }
    }
}
