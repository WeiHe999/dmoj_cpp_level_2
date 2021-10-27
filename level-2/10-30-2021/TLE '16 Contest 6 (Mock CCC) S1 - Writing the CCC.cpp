#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a;
    cin >> n; cin.ignore();
    string line;
    map <string, vector <int> > m1;
    vector <string> order;
    for (int x = 0; x < n; x++)
    {
        getline(cin, line);
        m1[line] = {};
        order.emplace_back(line);
    }
    cin >> a; cin.ignore();
    for (int b = 0; b < a; b++)
    {
        getline(cin, line);
        m1[line].emplace_back(b + 1);
    }
    for (auto c : order) for (auto d : m1[c]) cout << d << endl;
}
