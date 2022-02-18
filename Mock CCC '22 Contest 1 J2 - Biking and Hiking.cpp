#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k, s = 0;
    cin >> n >> k; cin.ignore();
    string a;
    getline(cin, a);
    bool flag = false;
    for (int b = 0; b < a.size(); b++)
    {
        if (flag)
        {
            if (a[b] == 'D')
            {
                flag = false;
                k++;
            }
            else s++;
        }
        else
        {
            if (a[b] == 'D') k++;
            if (a[b] == 'U')
            {
                k--;
                if (k == 0)
                {
                    flag = true;
                    s++;
                }
            }
        }
    }
    cout << s << endl;
}
