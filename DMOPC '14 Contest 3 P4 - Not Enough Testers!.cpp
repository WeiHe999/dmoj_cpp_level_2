#include <bits/stdc++.h>
using namespace std;

int main() 
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, k, a, b;
    cin >> t;
    vector <int> vec1(100050, 1);
    vector <vector <int> > vec2(100050);
    vec2[1].emplace_back(1);
    for (int x = 2; x < vec1.size(); x++)
    {
        for (int y = x; y < vec1.size(); y += x) vec1[y]++;
        vec2[vec1[x]].emplace_back(x);
    }
    for (int c = 0; c < t; c++)
    {
        cin >> k >> a >> b;
        cout << upper_bound(vec2[k].begin(), vec2[k].end(), b) - lower_bound(vec2[k].begin(), vec2[k].end(), a) << endl;
    }
}
