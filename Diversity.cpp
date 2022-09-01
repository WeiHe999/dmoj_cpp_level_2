#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, s = 0;
    cin >> n >> k;
    unordered_map <int, int> m1;
    vector <int> vec1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
        if (x < k) m1[a]++;
    }
    for (int x = k - 1; x < vec1.size() - 1; x++)
    {
        s = max(int(m1.size()), s);
        m1[vec1[x - k + 1]]--;
        if (m1[vec1[x - k + 1]] < 1) m1.erase(vec1[x - k + 1]);
        m1[vec1[x + 1]]++;
    }
    cout << max(int(m1.size()), s) << "\n";
}
