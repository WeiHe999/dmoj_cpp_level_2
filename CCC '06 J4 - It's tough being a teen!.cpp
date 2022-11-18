#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    unordered_map <int, unordered_set <int> > before = {{7, {1}}, {4, {1}}, {1, {2}}, {4, {3}}, {5, {3}}};
    unordered_set <int> vis;
    while (a != 0 && b != 0)
    {
        before[b].insert(a);
        cin >> a >> b;
    }
    vector <int> order;
    for (int x = 1; x <= 7; x++)
    {
        bool flag2 = true;
        for (int x = 1; x <= 7; x++)
        {
            if (!vis.count(x))
            {
                bool flag = true;
                for (auto c : before[x])
                {
                    if (!vis.count(c))
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    flag2 = false;
                    vis.insert(x);
                    order.emplace_back(x);
                    break;
                }
            }
        }
        if (flag2)
        {
            cout << "Cannot complete these tasks. Going to bed.\n";
            return 0;
        }
    }
    for (auto a : order) cout << a << " ";
    cout << "\n";
}
