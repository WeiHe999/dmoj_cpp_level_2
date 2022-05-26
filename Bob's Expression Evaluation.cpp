#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    for (int x = 0; x < 5; x++)
    {
        string s;
        getline(cin, s);
        bool flag = false;
        if (!isdigit(s[0]))
        {
            flag = true;
            reverse(s.begin(), s.end());
        }
        stack <string> d1;
        for (int x = 0; x < s.size(); x += 2)
        {
            if (isdigit(s[x])) d1.push(to_string(s[x] - '0'));
            else
            {
                int a = stoi(d1.top());
                d1.pop();
                int b = stoi(d1.top());
                d1.pop();
                if (s[x] == '+')
                {
                    d1.push(to_string(a + b));
                }
                else if (s[x] == '-')
                {
                    if (flag) d1.push(to_string(a - b));
                    else d1.push(to_string(b - a));
                }
                else if (s[x] == '*')
                {
                    d1.push(to_string(a * b));
                }
                else if (s[x] == '/')
                {
                    if (flag) d1.push(to_string(a / b));
                    else d1.push(to_string(b / a));
                }
                else
                {
                    if (flag) d1.push(to_string(a % b));
                    else d1.push(to_string(b % a));
                }
            }
        }
        cout << d1.top() << "\n";
    }
}
