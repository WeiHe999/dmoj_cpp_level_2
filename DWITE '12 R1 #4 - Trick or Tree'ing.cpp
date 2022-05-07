#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    string s;
    for (int x = 0; x < 5; x++)
    {
        getline(cin, s);
        int node = 0, depth = 0, sum = 0, counter = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ') continue;
            if (s[i] == '(')
            {
                counter++;
                node++;
                depth = max(counter, depth);
            }
            else if (s[i] == ')') counter--;
            else
            {
                node++;
                int c = 0;
                while (i < s.size() && isdigit(s[i]))
                {
                    c = c * 10 + (s[i] - '0');
                    i++;
                }
                sum += c;
                i--;
            }
        }
        cout << 2 * (node - 1) - depth << " " << sum << endl;
    }
}
