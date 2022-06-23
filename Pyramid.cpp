#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, cur = 1;
    cin >> n;
    vector <int> vec1;
    unordered_map <int, int> m1;
    for (int x = 0; x < n; x++)
    {
        cin >> a;
        vec1.emplace_back(a);
        if (a == cur)
        {
            m1[cur] = x;
            cur++;
        }
    }
    for (int b = cur - 1; b > 0; b--)
    {
        int curr = b;
        for (int c = m1[b] + 1; c < vec1.size(); c++)
        {
            if (vec1[c] == curr) curr--;
            if (curr == 0) break;
        }
        if (curr == 0)
        {
            cout << b << "\n";
            return 0;
        }
    }
    cout << 0 << "\n";
}
