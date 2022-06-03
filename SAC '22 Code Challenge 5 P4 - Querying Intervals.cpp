#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, a, b;
    cin >> n >> q;
    vector <pair <int, int> > vec2;
    vector <int> vec1;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec2.push_back({a, b});
    }
    stack <pair <int, int> > s1;
    sort(vec2.begin(), vec2.end());
    s1.push(vec2[0]);
    for (int y = 1; y < vec2.size(); y++)
    {
        if (s1.top().second + 1 >= vec2[y].first)
        {
            pair <int, int> tmp = s1.top();
            s1.pop();
            s1.push({tmp.first, max(vec2[y].second, tmp.second)});
        }
        else s1.push(vec2[y]);
    }
    while (!s1.empty())
    {
        vec1.emplace_back(s1.top().second);
        m1[s1.top().second] = s1.top().first;
        s1.pop();
    }
    sort(vec1.begin(), vec1.end());
    for (int z = 0; z < q; z++)
    {
        cin >> a >> b;
        int c = lower_bound(vec1.begin(), vec1.end(), b) - vec1.begin();
        if (c == vec1.size()) cout << "N\n";
        else if (m1[vec1[c]] <= a) cout << "Y\n";
        else cout << "N\n";
    }
}
