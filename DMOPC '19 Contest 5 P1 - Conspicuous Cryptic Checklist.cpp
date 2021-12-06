#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, m, b;
    string line;
    cin >> n >> m; cin.ignore();
    unordered_set <string> set1, set2;
    for (int x = 0; x < n; x++)
    {
        getline(cin, line);
        set1.insert(line);
    }
    int ans = 0;
    bool flag;
    for (int a = 0; a < m; a++)
    {
        flag = true;
        cin >> b; cin.ignore();
        for (int c = 0; c < b; c++)
        {
            getline(cin, line);
            if (find(set1.begin(), set1.end(), line) == set1.end()) flag = false;
        }
        if (flag == true) ans++;
    }
    cout << ans << endl;
}
