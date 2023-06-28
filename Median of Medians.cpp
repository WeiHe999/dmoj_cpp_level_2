#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> vec1;
    for (int i = 1; i <= n; i++)
    {
        vector <int> tmp;
        for (int j = 1; j <= n; j++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        sort(tmp.begin(), tmp.end());
        if (n % 2 == 1) vec1.emplace_back(tmp[(n / 2)]);
        else vec1.emplace_back((tmp[(n / 2) - 1] + tmp[(n / 2)]) / 2);
    }
    sort(vec1.begin(), vec1.end());
    if (n % 2 == 1) cout << vec1[(n / 2)] << "\n";
    else cout << (vec1[(n / 2) - 1] + vec1[(n / 2)]) / 2 << "\n";
}
