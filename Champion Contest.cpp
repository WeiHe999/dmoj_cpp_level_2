#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, k, a, b;
    cin >> n >> k;
    vector <pair <int, int> > vec1;
    unordered_map <int, int> m1, m2;
    for (int x = 1; x <= n; x++)
    {
        cin >> a;
        vec1.push_back({-1 * a, x});
        m2[x] = a;
    }
    sort(vec1.begin(), vec1.end());
    for (int y = 0; y < vec1.size(); y++)
    {
        int ind = upper_bound(vec1.begin(), vec1.end(), make_pair(vec1[y].first, INT_MAX)) - vec1.begin();
        if (ind == vec1.size()) m1[vec1[y].second] = 0;
        else m1[vec1[y].second] = n - ind;
    }
    for (int z = 0; z < k; z++)
    {
        cin >> a >> b;
        if (m2[a] > m2[b]) m1[a]--;
        if (m2[a] < m2[b]) m1[b]--;
    }
    for (int c = 1; c <= n; c++) cout << m1[c] << " ";
    cout << "\n";
}

