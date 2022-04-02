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
    int n, m, a, b;
    cin >> n >> m;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    sort(vec1.begin(), vec1.end());
    for (int y = 0; y < m; y++)
    {
        cin >> b;
        int c = lower_bound(vec1.begin(), vec1.end(), b) - vec1.begin();
        if (c == vec1.size()) cout << 0 << endl;
        else cout << vec1.size() - c << endl;
    }
}
