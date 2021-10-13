#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    string alpha = "qwertyuiopasdfghjklzxcvbnm";
    unordered_map <char, vector <string> > m1;
    unordered_map <char, int> m2;
    for (auto a : alpha) m1[a] = {};
    int k, n;
    string line;
    cin >> k >> n; cin.ignore();
    for (int x = 0; x < k; x++)
    {
        getline(cin, line);
        m1[line[0]].emplace_back(line);
    }
    for (auto b : alpha)
    {
        sort(m1[b].begin(), m1[b].end());
        m2[b] = 0;
    }
    char c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        cout << m1[c][m2[c]] << endl;
        m2[c]++;
        if (m2[c] == m1[c].size()) m2[c] = 0;
    }
}
