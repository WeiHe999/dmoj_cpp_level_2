#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        string str1, str2;
        cin >> str1 >> str2;
        int ind = 0;
        stack <char> s1;
        for (int y = 0; y < str1.size(); y++)
        {
            if (ind == str2.size())
            {
                ind = 0;
                break;
            }
            if (s1.empty())
            {
                if (str1[y] == str2[ind])
                {
                    ind++;
                    continue;
                }
                if (str1[y] < str2[ind])
                {
                    s1.push(str1[y]);
                }
                else
                {
                    break;
                }
            }
            else
            {
                char cur = str1[y];
                bool flag = false;
                while (!s1.empty() && s1.top() == cur && cur < 'z')
                {
                    s1.pop();
                    cur += 1;
                }
                if (s1.empty() && cur == str2[ind])
                {
                    ind++;
                } 
                else  s1.push(cur);
            }
        }
        if (ind == str2.size()) cout << "YES\n";
        else cout << "NO\n";
    }
}
