#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long n, m, k, s = 0;
    int a, b, w = INT_MAX;
    cin >> m >> n >> k;
    if (k == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    vector <int> vec1(m + 2, n), vec2(m + 2);
    for (int x = 0; x < n; x++)
    {
        cin >> a >> b;
        vec2[a]--;
        vec2[b + 1]++;
    }
    for (int x = 1, aa = 0; x < m + 2; x++)
    {
        aa += vec2[x];
        vec1[x] += aa;
    }
    a = 1;
    b = 1;
    for (; s < k && b <= m; b++) s += vec1[b];
    if (s < k)
    {
        cout << -1 << endl;
        return 0;
    }
    b--;
    while (b <= m)
    {
        while (s >= k)
        {
            s -= vec1[a];
            a++;
        }
        a--;
        s += vec1[a];
        if (b - a + 1 < w) w = b - a + 1;
        b++;
        s += vec1[b];
    }
    if (w == INT_MAX) cout << -1 << endl;
    else cout << w << endl;
}
