#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, base;
    cin >> n;
    vector <long long> vec1(n + 1);
    pair <long long, long long> min_p = {INT_MAX, 0};
    bool flag = true;
    for (long long x = 2; x <= n; x++)
    {
        cout << "? " << x << " " << 1 << '\n' << flush;
        cin >> a;
        vec1[x] = a;
        min_p = min(min_p, {vec1[x], x});
        if (vec1[x] > n) flag = false;
    }
    if (flag) base = 1;
    else base = vec1[min_p.second];
    cout << "! " << base << flush;
    for (long long y = 2; y <= n; y++)
    {
        cout << " " << (vec1[y] / base) << flush;
    }
    cout << '\n';
}
