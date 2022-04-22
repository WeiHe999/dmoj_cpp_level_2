#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, t;
    cin >> n;
    for (int x = 0; x < n; x++)
    {
        cin >> t;
        unordered_map <int, int> m1;
        m1[0] = t;
        int r = 0;
        cout << "Round " << r << ": " << m1[0] << " undefeated, " << m1[1] << " one-loss, " << m1[2] << " eliminated" << endl;
        while (m1[0] != 1 || m1[1] != 1)
        {
            r++;
            int tmp = m1[1] - ceil(m1[1] / 2.0);
            m1[1] = ceil(m1[1] / 2.0);
            m1[2] += tmp;
            tmp = m1[0] - ceil(m1[0] / 2.0);
            m1[0] = ceil(m1[0] / 2.0);
            m1[1] += tmp;
            cout << "Round " << r << ": " << m1[0] << " undefeated, " << m1[1] << " one-loss, " << m1[2] << " eliminated" << endl;
        }
        cout << "Round " << r + 1 << ": " << 0 << " undefeated, " << 2 << " one-loss, " << m1[2] << " eliminated" << endl;
        cout << "Round " << r + 2 << ": " << 0 << " undefeated, " << 1 << " one-loss, " << m1[2] + 1 << " eliminated" << endl;
        cout << "There are " << r + 2 << " rounds." << endl;
        if (x != n - 1) cout << endl;
    }
}
