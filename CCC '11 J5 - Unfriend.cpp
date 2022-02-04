#include <bits/stdc++.h>
using namespace std;

int ways(int node, int total, vector <int> vec1)
{
    vector <int> vec2;
    for (int i = 0; i < vec1.size(); i++) if (vec1[i] == node) vec2.emplace_back(i + 1);
    if (vec2.empty()) return 2;
    for (int j = 0; j < vec2.size(); j++) total = total * ways(vec2[j], 1, vec1);
    return total + 1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1;
    for (int x = 1; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    cout << ways(n, 1, vec1) - 1 << endl;
}
