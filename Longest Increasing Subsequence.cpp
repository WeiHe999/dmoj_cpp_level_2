#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    vector <int> list = {vec1[1]};
    for (int i = 2; i <= n; i++)
    {
        if (vec1[i] > list.back()) list.emplace_back(vec1[i]);
        else list[lower_bound(list.begin(), list.end(), vec1[i]) - list.begin()] = vec1[i];
    }
    cout << list.size() << "\n";
}
