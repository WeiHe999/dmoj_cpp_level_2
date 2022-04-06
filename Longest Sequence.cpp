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
    long long l, r, cur, s = 0;
    cin >> l >> r;
    cur = l;
    while (cur <= r)
    {
        cur *= 2;
        s++;
    }
    cout << s << endl;
}
