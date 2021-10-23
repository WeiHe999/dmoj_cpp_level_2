#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, p, a, b;
    cin >> n;
    unordered_map <int, vector <int> > m1 = {{1, {0, 0}}};
    set <vector <int> > s1 = {{0, 0}};
    for (int x = 2; x <= n; x++)
    {
        cin >> p >> a >> b;
        m1[x] = {m1[p][0] + a, m1[p][1] + b};
        s1.insert(m1[x]);
    }
    cout << s1.size() << endl;
}
