#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    vector <pair <int, int> > vec1;
    for (auto x : m1) vec1.push_back({x.second, x.first});
    sort(vec1.rbegin(), vec1.rend());
    if (vec1[0].first == vec1[1].first)
    {
        int best = 1;
        for (int x = 2; x < vec1.size(); x++)
        {
            if (vec1[x].first == vec1[0].first) best = x;
            else break;
        }
        cout << max(abs(vec1[0].second - vec1[best].second), abs(vec1[0].second - vec1[1].second)) << "\n";
    }
    else
    {
        if (vec1.size() > 2 && vec1[1].first == vec1[2].first)
        {
            int best2 = 2;
            for (int x = 3; x < vec1.size(); x++)
            {
                if (vec1[x].first == vec1[2].first) best2 = x;
                else break;
            }
            cout << max(abs(vec1[0].second - vec1[best2].second), abs(vec1[0].second - vec1[1].second)) << "\n";
        }
        else cout << abs(vec1[0].second - vec1[1].second) << "\n";
    }
}
