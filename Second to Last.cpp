#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <pair <int, int> > vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(make_pair(a, x + 1));
    }
    sort(vec1.rbegin(), vec1.rend());
    cout << vec1[1].second << "\n";
}
