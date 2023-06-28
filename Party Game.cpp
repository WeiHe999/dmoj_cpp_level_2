#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0;
    cin >> n;
    unordered_map <int, int> m1;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> vec1[i];
        m1[vec1[i]]++;
        s = max(vec1[i], s);
    }
    vector <int> vec2(s + 1);
    for (auto x : m1)
    {
        for (int y = x.first; y <= s; y += x.first) vec2[y] += x.second;
        vec2[x.first]--;
    }
    for (int i = 1; i <= n; i++) cout << vec2[vec1[i]] << "\n";
}
