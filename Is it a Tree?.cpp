#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a;
    unordered_map <int, vector <int> > graph;
    for (int x = 1; x <= 4; x++)
    {
        for (int y = 1; y <= 4; y++)
        {
            cin >> a;
            if (a == 1)
            {
                graph[x].emplace_back(y);
            }
        }
    }
    int s = 0;
    for (int x = 1; x < 5; x++)
    {
        if (!graph.count(x))
        {
            cout << "No\n";
            return 0;
        }
        s += graph[x].size();
    }
    if (s == 6) cout << "Yes\n";
    else cout << "No\n";
}
