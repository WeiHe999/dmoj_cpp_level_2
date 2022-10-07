#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n; cin.ignore();
    string str1;
    for (int x = 0; x < n; x++)
    {
        cin >> str1;
        int cnt = 0;
        char c;
        for (int a = 0; a < str1.size(); a++)
        {
            if (a == 0)
            {
                c = str1[a];
            }
            else if (str1[a] != c)
            {
                cout << cnt << " " << c << " ";
                cnt = 0;
                c = str1[a];
            }
            cnt++;
        }
        cout << cnt << " " << c << "\n";
    }
}
