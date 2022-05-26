#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, maxa = INT_MIN;
    cin >> n;
    vector <int> vec1, psa1, psa2;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
    }
    for (int y = 0; y < vec1.size(); y++)
    {
        if (y == 0) psa1.emplace_back(vec1[y]);
        else psa1.emplace_back(__gcd(vec1[y], psa1.back()));
    }
    for (int z = vec1.size() - 1; z >= 0; z--)
    {
        if (z == vec1.size() - 1) psa2.emplace_back(vec1[z]);
        else psa2.emplace_back(__gcd(vec1[z], psa2.back()));
    }
    reverse(psa2.begin(), psa2.end());
    for (int ind = 0; ind < n; ind++)
    {
        int b;
        if (ind == 0) b = psa2[1];
        else if (ind == n - 1) b = psa1[n - 2];
        else b = __gcd(psa1[ind - 1], psa2[ind + 1]);
        maxa = max(b, maxa);
    }
    cout << maxa << "\n";
}
