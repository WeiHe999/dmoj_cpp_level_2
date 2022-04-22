#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << endl;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t, n;
    cin >> t;
    for (int x = 0; x < t; x++)
    {
        cin >> n;
        if (n == 0) cout << 0 << endl;
        if (n == 2) cout << 2 << endl;
        else cout << n - 1 << endl;
    }
}
