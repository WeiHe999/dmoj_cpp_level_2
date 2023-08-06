#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, m;
    string str1, inorout;
    cin >> t >> m;
    deque <string> q1;
    for (int i = 1; i <= t; i++)
    {
        cin >> str1 >> inorout;
        if (inorout == "in") q1.push_front(str1);
        else if (q1.front() == str1 || q1.back() == str1)
        {
            if (q1.back() == str1 && m >= 1)
            {
                q1.pop_back();
                m--;
            }
            else q1.pop_front();
        }
    }
    while (!q1.empty())
    {
        cout << q1.back() << "\n";
        q1.pop_back();
    }
}
