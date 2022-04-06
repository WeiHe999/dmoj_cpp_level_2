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
    int n, k, a, maxa = INT_MIN, second = INT_MIN, s;
    cin >> n >> k;
    unordered_map <int, int> m1;
    vector <int > vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        m1[a]++;
    }
    for (auto b : m1) vec1.emplace_back(b.second);
    sort(vec1.rbegin(), vec1.rend());
    s = 0;
    for (int c = 0; c < vec1.size(); c++)
    {
        if (c>=k) s+= vec1[c];
    }
    cout << s << endl;
}
