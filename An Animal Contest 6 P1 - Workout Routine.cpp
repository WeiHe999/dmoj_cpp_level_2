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
    long long n, k, sum = 0;
    cin >> n >> k;
    vector <long long> vec1;
    for (long long a = 1; a < n; a++)
    {
        vec1.emplace_back(a);
        sum += a;
    }
    long long h = ceil(sum*1.0/k);
    long long b = h*k - sum;
    while (b < n) b += k;
    if (b > 1000000000)
    {
        cout << -1 << endl;
        return 0;
    }
    for (auto c : vec1) cout << c << " ";
    cout << b << endl;
}
