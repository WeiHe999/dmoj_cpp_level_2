#include <bits/stdc++.h>
using namespace std;

template < typename T > void print (T t)
{
    for (const auto & e:t) cout << e << " ";
    cout << "\n";
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a;
    cin >> n;
    unordered_set <int> s1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        s1.insert(a);
    }
    cout << s1.size() << "\n";
}
