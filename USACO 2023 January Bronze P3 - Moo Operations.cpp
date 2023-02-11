#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int q;
    cin >> q;
    for (int x = 0; x < q; x++)
    {
        string str1;
        cin >> str1;
        int s = 1e9;
        if (str1.size() <= 2)
        {
            cout << "-1\n";
            continue;
        }
        for (int i = 1; i < str1.size() - 1; i++)
        {
            if (str1[i] == 'O')
            {
                int tmp = str1.size() - 3;
                if (str1[i - 1] != 'M') tmp++;
                if (str1[i + 1] != 'O') tmp++;
                s = min(tmp, s);
            }
        }
        if (s == 1e9) cout << "-1\n";
        else cout << s << "\n";
    }
}
