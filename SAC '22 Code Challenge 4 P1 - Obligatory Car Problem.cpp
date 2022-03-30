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
    long long a;
    cin >> a;
    if (a < 3) cout << 0 << endl;
    else cout << a - 3 << endl;
}
