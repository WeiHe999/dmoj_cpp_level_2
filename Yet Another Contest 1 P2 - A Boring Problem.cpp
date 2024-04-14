#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, s = 0;
string str1;
vector <char> vec1;
unordered_map <int, vector <int> > graph;
vector <int> same, diff;
vector <pair <int, int> > edges;

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    vec1.resize(n + 1);
    same.resize(n + 1);
    diff.resize(n + 1);
    cin >> str1;
    for (int i = 0; i < str1.size(); i++) vec1[i + 1] = str1[i];
    for (int i = 1, a, b; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        edges.push_back({a, b});
        if (vec1[a] == vec1[b])
        {
            same[a]++;
            same[b]++;
        }
        else
        {
            diff[a]++;
            diff[b]++;
        }
    }
    s += n - 1;
    for (int i = 1; i <= n; i++) s += same[i] * diff[i] + (diff[i] * (diff[i] - 1)) / 2;
    for (auto x : edges)
    {
        if (vec1[x.first] == vec1[x.second]) s += diff[x.first] * diff[x.second];
        else s += same[x.first] * same[x.second] + (diff[x.first] - 1) * (diff[x.second] - 1);
    }
    cout << (n * (n - 1)) / 2 - s << "\n";
}
