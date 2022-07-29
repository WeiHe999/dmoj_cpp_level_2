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
    int n, a, v;
    cin >> n;
    char b;
    deque <pair <int, int> > d1;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> b >> a;
        if (b == 'F') d1.push_front({a, x + 1});
        if (b == 'E') d1.push_back({a, x + 1});
        if (b == 'R') m1[a] = x + 1;
    }
    for (auto c : d1) if (!m1.count(c.first) || m1[c.first] < c.second) cout << c.first << "\n";
}
