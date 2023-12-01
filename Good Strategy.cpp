#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    vector <int> vec1(n + 1);
    unordered_set <int> team1;
    set <pair <int, int> > s1;
    for (int i = 1; i <= n; i++) s1.insert({0, -i});
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        if (a == 1) team1.insert(b);
        s1.erase({vec1[b], -b});
        vec1[b]++;
        if (!team1.count(b) && a == 2) s1.insert({vec1[b], -b});
        if (s1.empty()) cout << "Make noise\n";
        else cout << -(*s1.rbegin()).second << " " << -(*s1.begin()).second << "\n";
    }
}
