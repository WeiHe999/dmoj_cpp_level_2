#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int k, s, l, ind = 0;
    cin >> k; cin.ignore();
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ", ans, line;
    getline(cin, line);
    for (int i = 0; i < line.length(); i++)
    {
        ind++;
        s = 3 * ind + k;
        l = line[i] - 64 - s;
        while (l <= 0) l += 26;
        ans += char(l + 64);
    }
    cout << ans << endl;
}
