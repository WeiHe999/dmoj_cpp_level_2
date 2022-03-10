#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1, pos;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int y = 0; y < n; y++)
    {
        cin >> a;
        m1[a] = y + 1;
    }
    for (auto z : vec1) pos.emplace_back(m1[z]);
    int maxa = INT_MIN, cnt = 0;
    for (int b = 0; b < pos.size(); b++)
    {
        if (pos[b] > maxa) maxa = pos[b];
        else cnt++;
    }
    cout << cnt << endl;
}
