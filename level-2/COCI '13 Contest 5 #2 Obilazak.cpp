#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int k, a, ind, d;
    cin >> k;
    vector <int> vec1, all, tmp;
    for (int x = 0; x < pow(2, k) - 1; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    all.emplace_back(vec1.size() / 2);
    for (int i = 0; i < k; i++)
    {
        if (i == 0)
        {
            cout << vec1[vec1.size() / 2] << endl;
            continue;
        }
        tmp = {};
        for (auto x : all)
        {
            tmp.emplace_back(x - pow(2, (k - i - 1)));
            tmp.emplace_back(x + pow(2, (k - i - 1)));
        }
        for (int j = 0; j < pow(2, i); j++) cout << vec1[tmp[j]] << " ";
        cout << endl;
        all = tmp;
    }
}
