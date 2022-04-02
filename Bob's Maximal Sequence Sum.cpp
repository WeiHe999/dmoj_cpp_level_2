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
    long long n, a;
    cin >> n;
    vector <long long> vec1;
    for (long long x = 1; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    long long sum = 0;
    sum += vec1[0];
    for (long long y = 1; y < vec1.size(); y++)
    {
        sum += min(vec1[y], vec1[y - 1]);
    }
    sum += vec1.back();
    cout << sum << endl;
}
