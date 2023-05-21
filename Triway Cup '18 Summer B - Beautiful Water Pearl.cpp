#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int c, d, e, s = 1;
    cin >> c >> d >> e;
    vector <int> vec1(32);
    for (int i = 31; i >= 0; i--)
    {
        bool a1 = c & (1 << i), a2 = d & (1 << i), a3 = e & (1 << i);
        vector <pair <int, int> > options = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
        for (auto x : options) if ((x.first + x.second >= a1) && (x.first * x.second == a2) && (abs(x.first - x.second) == a3)) vec1[i]++;
    }
    for (auto x : vec1) s *= x;
    cout << s << "\n";
}
