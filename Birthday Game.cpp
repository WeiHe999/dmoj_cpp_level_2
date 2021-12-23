#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, a, min = INT_MAX;
    pair <int, int> max;
    cin >> n;
    unordered_map <int, int> m1, m2;
    vector <int> visited(n+1);
    for (int x = 1; x <= n; x++)
    {
        cin >> a;
        m1[x] = a;
    }
    for (int b = 1; b <= n; b++)
    {
        if (visited[b]) continue;
        m2 = {};
        int current = b, s = 1;
        while (true)
        {
            m2[current] = s;
            if (visited[current]) 
            {
                break;
            }
            visited[current] = 1;
            s++;
            current = m1[current];
            if (s - m2[current] == 1)
            {
                cout << 1 << endl;
                return 0;
            }
            if (m2.count(current) && m2[current] != 0)
            {
                if (s - m2[current] < min) min = s - m2[current];
                break;
            }
        }
    }
    cout << min << endl;
}
