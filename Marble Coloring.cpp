#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, prev = 0;
    cin >> n;
    vector <int> vec1(n + 1);
    vector <pair <int, int> > vec2;
    unordered_map <int, int> m1;
    stack <pair <int, int> > s1;
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    for (int i = 1; i <= n; i++)
    {
        while (!s1.empty() && s1.top().first != vec1[i] && m1.count(vec1[i]))
        {
            m1[s1.top().first]--;
            if (m1[s1.top().first] == 0) m1.erase(s1.top().first);
            s1.pop();
        }
        if (!s1.empty() && m1.count(vec1[i]))
        {
            m1[vec1[i]]--;
            if (m1[vec1[i]] == 0) m1.erase(vec1[i]);
            s1.pop();
        }
        s1.push({vec1[i], i});
        m1[vec1[i]]++;
    }
    while (!s1.empty())
    {
        vec2.push_back({s1.top().second, s1.top().first});
        s1.pop();
    }
    sort(vec2.begin(), vec2.end());
    for (auto x : vec2)
    {
        for (int i = prev + 1; i <= x.first; i++) cout << x.second << "\n";
        prev = x.first;
    }
}
