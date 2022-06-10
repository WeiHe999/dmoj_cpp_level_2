#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int x, n, a, sum = 0;
    cin >> x >> n;
    vector <int> vec1;
    for(int i = 0; i < n; i++)
    {
        cin >> a;
        vec1.emplace_back(a);
        sum += vec1.back();
    }
    cout << x * (n + 1) - sum << "\n";
}
