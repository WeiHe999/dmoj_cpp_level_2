#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a;
    cin >> n;
    unordered_set <int> set1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        set1.insert(a);
    }
    cout << set1.size() << endl;
}
