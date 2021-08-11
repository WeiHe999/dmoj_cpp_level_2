#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.sync_with_stdio (0);
    cin.tie (0);
    stack <char> s1;
    int balanced;
    for (int x = 0; x < 5; x++)
    {
        balanced = 1;
        s1 = {};
        string line;
        getline(cin, line);
        for (auto a : line)
        {
            if (s1.empty())
            {
                if (a == ')')
                {
                    s1.push(0);
                    break;
                }
                if (a == '}')
                {
                    s1.push(0);
                    break;
                }
                if (a == ']')
                {
                    s1.push(0);
                    break;
                }
            }
            if (a == '(' || a == '{' || a == '[') s1.push(a);
            if (a == ')')
            {
                if (s1.top() == '(') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
            if (a == '}')
            {
                if (s1.top() == '{') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
            if (a == ']')
            {
                if (s1.top() == '[') s1.pop();
                else
                {
                    balanced = 0;
                    break;
                }
            }
        }
        if (s1.empty()) cout << "balanced" << endl;
        else cout << "not balanced" << endl;
    }
}
