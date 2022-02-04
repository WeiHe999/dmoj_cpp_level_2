#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    vector <int> even, odd;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        if (a % 2 == 0) even.emplace_back(a);
        else odd.emplace_back(a);
    }
    cout << even.size() / 2 + odd.size() / 2 << endl;
}
