#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        vector <int> tmp;
        for (int y = 0; y < n; y++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        sort(tmp.begin(), tmp.end());
        vec1.emplace_back(tmp[n / 2]);
    }
    sort(vec1.begin(), vec1.end());
    cout << vec1[n / 2] << "\n";
}
