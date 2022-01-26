#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    string line;
    getline(cin, line);
    stack <char> s1;
    s1.push(line[0]);
    for (int a = 1; a < line.length(); a++)
    {
        if (!s1.empty() && line[a] == ')' && s1.top() == '(') s1.pop();
        else s1.push(line[a]);
    }
    if (s1.size() == 0 || s1.size() == 2) cout << "YES" << endl;
    else cout << "NO" << endl;
}
