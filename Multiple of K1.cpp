#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, k, a, max_diff = -1;
    cin >> n >> k;
    vector <long long> vec1 = {0};
    unordered_map <long long, vector <long long> > m1;
    for (long long x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a + vec1.back());
    }
    for (long long y = 0; y < vec1.size(); y++)
    {
        m1[vec1[y] % k].emplace_back(y);
    }
    for (auto b : m1)
    {
        if (b.second.size() >= 2) max_diff = max(b.second.back() - b.second[0], max_diff);
    }
    cout << max_diff << "\n";
}
