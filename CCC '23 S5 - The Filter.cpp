#include <bits/stdc++.h>
using namespace std;

void filter(long long i, double l, double r, vector <long long> &vec1)
{
    if (i == 0) for (long long x = ceil(l); x <= floor(r); x++) vec1.push_back(x);
    else
    {
        filter(i - 1, l, l + (r - l) / 3, vec1);
        filter(i - 1, l + 2 * (r - l) / 3, r, vec1);
    }
}

bool rec(long long x, double n, unordered_map <long long, bool> &cycle)
{
    if (x * 3 > n && x * 3 < 2 * n) return false;
    if (x * 3 <= n)
    {
        x = x * 3;
        if (cycle[x]) return true;
        cycle[x] = true;
        return rec(x, n, cycle);
    }
    else
    {
        x = x * 3 - n * 2;
        if (cycle[x]) return true;
        cycle[x] = true;
        return rec(x, n, cycle);
    }
}

int main()
{
    double n;
    cin >> n;
    vector <long long> vec1;
    filter(19, 0, n, vec1);
    unordered_map <long long, bool> cycle;
    for (auto x : vec1)
    {
        if (rec(x, n, cycle)) cout << x << "\n";
        cycle = {};
    }
}
