#include <bits/stdc++.h>
using namespace std;

long long n, q, t, a;
vector <long long> vec1;

long long lcm(long long a, long long b)
{
    return (a * b) / __gcd(a, b);
}

long long binary_search(long long l, long long r, long long t)
{
    if (l == r) return l;
    long long m = (l + r) / 2;
    if (t % vec1[m] == 0) return binary_search(m + 1, r, t);
    return binary_search(l, m, t);
}

int main() 
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    vec1.emplace_back(1);
    for (long long z = 1; z <= n; z++)
    {
        cin >> a;
        vec1.emplace_back(lcm(vec1[z - 1], a));
        if (vec1[z] > 1000000000) vec1[z] = 1000000001;
    }
    for (long long x = 0; x < q; x++)
    {
        cin >> t;
        if (t % vec1[n] == 0) cout << -1 << endl;
        else cout << binary_search(1, n, t) << endl;
    }
}
