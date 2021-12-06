#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n; cin.ignore();
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int ans = 0;
    bool flag = false;
    for (int x = 0; x < n; x++)
    {
        if (a[x] != b[x])
        {
            if (!flag)
            {
                flag = true;
                ans++;
            }
        }
        else flag = false;
    }
    cout << ans << endl;
}
