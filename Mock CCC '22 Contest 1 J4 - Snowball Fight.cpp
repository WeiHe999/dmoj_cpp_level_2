#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t, a;
    cin >> n >> t;
    vector <int> vec_last;
    unordered_map <int, deque <pair <int, int> > > m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec_last.emplace_back(a);
        m1[x + 1].push_back({a, 0});
    }
    // for (auto b : m1)
    // {
    //     cout << b.first << ": ";
    //     for (auto c : b.second)
    //     {
    //         cout << c.first << ", " << c.second << endl;
    //     }
    //     cout << endl;
    // }
    for (int y = 0; y < t; y++)
    {
        for (int z = 1; z <= n; z++)
        {
            if (m1[z].size() != 0)
            {
                pair <int, int> current = m1[z].front();
                if (current.second < y + 1)
                {
                    m1[z].pop_front();
                    m1[current.first].push_back({z, y + 1});
                    vec_last[z - 1] = current.first;
                }
            }
        }
        // cout << "Round " << y + 1 << ":" << endl;
        // for (auto b : m1)
        // {
        //     cout << b.first << ": ";
        //     for (auto c : b.second)
        //     {
        //         cout << c.first << ", " << c.second << endl;
        //     }
        //     cout << endl;
        // }
    }
    for (int c = 0; c < vec_last.size(); c++)
    {
        if (c == 0) cout << vec_last[c];
        else cout << " " << vec_last[c];
    }
    cout << endl;
}
