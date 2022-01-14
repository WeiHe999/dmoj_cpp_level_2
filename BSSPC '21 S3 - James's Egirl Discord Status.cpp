#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a, s = 0, c;
    vector <long long> psa = {0};
    cin >> n >> k;
    for (int b = 1; b <= n; b++)
    {
        cin >> a;
        psa.emplace_back(a + psa[b - 1]);
    }
    for (int i = 0; i < k; i++)
    {
        c = ((n - i) / k) + 1;
        vector <long long> vec1(c);
        vec1[c - 1] = psa[i + k * c - k];
        for (int x = c - 2; x >= 0; x--) vec1[x] = max(vec1[x + 1], psa[i + k * x]);
        for (int d = 0; d < c; d++) s = max(s, vec1[d] - psa[i + k * d]);
    }
    cout << s << endl;
}
