#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, ans = 0, vec1[1000001], vec2[1000001];
    cin >> n >> m;
    memset(vec2, -0x3f, sizeof vec2);
    memset(vec1, 0x3f, sizeof vec1);
    for (auto i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        vec1[x] = min(vec1[x], i);
        vec2[x] = max(vec2[x], i);
    }
    for (auto i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        ans = max(ans, vec2[b] - vec1[a] + 1);
    }
    cout << ans << endl;
}
