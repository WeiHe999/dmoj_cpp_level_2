#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, l;
    cin >> n >> l;
    vector <string> vec1(n);
    for (int i = 0; i < n; i++) cin >> vec1[i];
    sort(vec1.rbegin(), vec1.rend());
    for (auto x : vec1) cout << x;
    cout << "\n";
}
