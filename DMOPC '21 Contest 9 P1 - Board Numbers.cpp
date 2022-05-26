#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, a, lb = 1, rb = LLONG_MAX, acc = 0;
    cin >> n;
    vector <long long> vec1;
    for (long long x = 1; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (long long x = 0; x < vec1.size(); x++)
    {
        acc += pow(-1, x) * vec1[x];
        if (x % 2 == 1) lb = max(lb, acc + 1);
        else rb = min(rb, acc - 1);
    }
    cout << max((long long)0, rb - lb + 1) << "\n";
}
