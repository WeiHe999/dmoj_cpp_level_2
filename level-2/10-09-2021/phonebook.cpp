#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.sync_with_stdio (0); cin.tie (0);
    int n, a, d, c;
    cin >> n;
    string name;
    unordered_map <int, string> m1;
    unordered_map <string, int> m2, m3;
    for (int x = 0; x < n; x++)
    {
        cin >> name >> a;
        m1[a] = name;
        m2[name] = 0;
        m3[name] = a;
    }
    cin >> d;
    for (int b = 0; b < d; b++)
    {
        cin >> c;
        m2[m1[c]]++;
    }
    int m = -1 * INT_MAX;
    string m_name;
    int m_phone = 99999999;
    for (auto e : m2)
    {
        if (e.second > m || (e.second == m && m3[e.first] <= m_phone))
        {
            m = e.second;
            m_name = e.first;
            m_phone = m3[m_name];
        }
    }
    cout << m_name << endl;
}
