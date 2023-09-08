#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, cycles = 0;
    cin >> n >> m;
    vector <int> vec1(n + 1);
    for (int i = 1; i <= n; i++) cin >> vec1[i];
    unordered_set <int> s1;
    for (int i = 1; i <= n; i++)
    {
        s1.insert(vec1[i]);
        if (s1.size() == m)
        {
            s1 = {};
            cycles++;
        }
    }
    cout << cycles + 1 << "\n";
}
