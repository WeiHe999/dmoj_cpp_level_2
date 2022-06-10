#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, s = 0, max_s = 0;
    cin >> n;
    vector <int> vec1(n), vec2;
    for (int x = 0; x < n; x++) cin >> vec1[x];
    for (int x = 1; x < n; x++)
    {
        if (abs(vec1[x] - vec1[x - 1]) <= 2) vec2.emplace_back(1);
        else vec2.emplace_back(0);
    }
    for (auto y : vec2)
    {
        if (y == 1) s++;
        else
        {
            max_s = max(s, max_s);
            s = 0;
        }
    }
    cout << max(s + 1, max_s + 1) << "\n";
}
