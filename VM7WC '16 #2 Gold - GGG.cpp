#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a;
    cin >> n;
    vector <int> vec1(n + 1), v1, list;
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    cin >> m;
    vector <int> vec2(m + 1);
    for (int i = 1; i <= m; i++) cin >> vec2[i];
    unordered_map <int, int> m1;
    for (int i = 1; i <= n; i++) m1[vec1[i]] = i;
    for (int i = 1; i <= m; i++)
    {
        if (m1.count(vec2[i])) v1.emplace_back(m1[vec2[i]]);
    }
    if (v1.size()==0)
    {
        cout << 0 << endl;
        return 0;
    }
    list = {v1[0]};
    for (int i = 1; i < v1.size(); i++)
    {
        if (v1[i] > list.back()) list.emplace_back(v1[i]);
        else list[lower_bound(list.begin(), list.end(), v1[i]) - list.begin()] = v1[i];
    }
    cout << list.size() << "\n";
}
