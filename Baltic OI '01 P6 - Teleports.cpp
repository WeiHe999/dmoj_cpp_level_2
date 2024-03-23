#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int m, n;
    cin >> m >> n;
    vector <int> vec1(m + 1), vec2(n + 1), res1(m + 1), res2(n + 1);
    for (int i = 1; i <= m; i++) cin >> vec1[i];
    for (int i = 1; i <= n; i++) cin >> vec2[i];
    for (int i = 1; i <= m; i++)
    {
        res1[i]++;
        res2[vec1[i]]--;
    }
    queue <int> q1;
    for (int i = 1; i <= n; i++) if (res2[i] == 0) q1.push(i);
    while (!q1.empty())
    {
        int cur = q1.front();
        q1.pop();
        res2[cur]++;
        if (res1[vec2[cur]] > 0) res1[vec2[cur]] = 0;
        res1[vec2[cur]]--;
        if (res1[vec2[cur]] > -2) res2[vec1[vec2[cur]]]++;
        if (res2[vec1[vec2[cur]]] == 0) q1.push(vec1[vec2[cur]]);
    }
    for (int i = 1; i <= m; i++)
    {
        if (res1[i] < 0) cout << 0;
        else cout << 1;
    }
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        if (res2[i] < 0) cout << 0;
        else cout << 1;
    }
    cout << "\n";
}
