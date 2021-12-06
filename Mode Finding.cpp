#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, max = INT_MIN, max_num;
    cin >> n;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    vector <int> vec1;
    for (auto a : m1)
    {
        if (a.second > max)
        {
            max = a.second;
            vec1 = {a.first};
        }
        if (a.second == max)
        {
            vec1.emplace_back(a.first);
        }
    }
    sort(vec1.begin(), vec1.end());
    cout << vec1[0] << endl;
}
