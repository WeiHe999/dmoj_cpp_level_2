#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, a, b;
    cin >> n >> m;
    double current = 1.0, tmp;
    unordered_map <int, double> m1;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        tmp = current * (b / 100.0);
        m1[a] += tmp;
        current -= tmp;
    }
    for (int j = 1; j <= n; j++)
    {
        cout << fixed << setprecision(6) << m1[j] << endl;
    }
}
