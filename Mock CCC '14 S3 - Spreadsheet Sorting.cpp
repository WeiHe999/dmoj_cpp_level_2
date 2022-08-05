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
    int r, c, a, n, col;
    cin >> r >> c;
    vector <vector <int> > vec1;
    vector <int> tmp;
    for (int x = 0; x < r; x++)
    {
        tmp = {};
        for (int y = 0; y < c; y++)
        {
            cin >> a;
            tmp.emplace_back(a);
        }
        vec1.push_back(tmp);
    }
    cin >> n;
    for (int b = 0; b < n; b++)
    {
        cin >> col;
        col--;
        stable_sort(vec1.begin(), vec1.end(), [col](vector <int> a, vector <int> b){return a[col] < b[col];});
    }
    for (auto d : vec1)
    {
        for (int e = 0; e < d.size(); e++)
        {
            if (e == d.size() - 1) cout << d[e];
            else cout << d[e] << " ";
        }
        cout << endl;
    }
}
