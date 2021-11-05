#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, c, d, e, f, g;
    string line, a, s, t1 = "********", t2 = "********", t3 = "********", t4 = "********", alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cin >> n; cin.ignore();
    vector <string> l;
    for (int i = 0; i < n; i++)
    {
        getline(cin, line);
        l.emplace_back(line);
    }
    getline(cin, a);
    d = a.size();
    for (int x = 0; x < n; x++) if (l[x].substr(0, d) == a) s += l[x][d];
    for (int b = 0; b < 26; b++)
    {
        g = s.find(alpha[b]);
        if (g != -1)
        {
            if (b < 5) t1[b + 3] = alpha[b];
            else if (b < 13) t2[b - 5] = alpha[b];
            else if (b < 21) t3[b - 13] = alpha[b];
            else t4[b - 21] = alpha[b];
        }
    }
    cout << t1 << endl << t2 << endl << t3 << endl << t4 << endl;
}
