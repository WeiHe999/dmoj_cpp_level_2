#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, b, r, c, d;
    long long s = 0;
    cin >> n >> a >> b >> r;
    vector <int> da(n + 1), vec1 = {0};
    for (long long x = 0; x < r; x++)
    {
        cin >> c >> d;
        da[c - 1]++;
        da[d]--;
    }
    for (long long f = 0; f < da.size(); f++)
    {
        vec1.emplace_back(vec1.back() + da[f]);
    }
    for (long long e = a; e <= b; e++)
    {
        s += vec1[e];
    }
    cout << s << "\n";
}
