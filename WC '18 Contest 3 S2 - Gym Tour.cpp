#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5 + 1;
unordered_map <int, vector <int> > graph;
vector <bool> vec1(MM), vec2(MM);
vector <int> d1(MM), d2(MM);
unordered_set <int> set1;
int n, k, f, a, b, distance1 = 0, distance2 = 0, s1 = 0, s2 = 0, s = -1;

void dfs1(int cur, int prev)
{
    if (set1.count(cur)) vec1[cur] = true;
    for (auto x: graph[cur])
    {
        if (x == prev) continue;
        dfs1(x, cur);
        if (vec1[x]) vec1[cur] = true;
    }
}

void dfs2(int cur, int prev)
{
    for (auto x: graph[cur])
    {
        if (x == prev) continue;
        if ((!vec1[cur]) || (!vec1[x])) continue;
        d1[x] = d1[cur] + 1;
        distance1 = max(distance1, d1[x]);
        s1++;
        dfs2(x, cur);
    }
}

void dfs3(int cur, int prev)
{
    if (set1.count(cur)) vec2[cur] = true;
    for (auto x: graph[cur])
    {
        if (x == prev) continue;
        dfs3(x, cur);
        if (vec2[x]) vec2[cur] = true;
    }
}

void dfs4(int cur, int prev)
{
    for (auto x: graph[cur])
    {
        if (x == prev) continue;
        if ((!vec2[cur]) || (!vec2[x])) continue;
        d2[x] = d2[cur] + 1;
        distance2 = max(distance2, d2[x]);
        s2++;
        dfs4(x, cur);
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> k >> f;
    for (int i = 1; i <= k; i++)
    {
        cin >> a;
        set1.insert(a);
    }
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs1(1, -1);
    dfs2(1, -1);
    s = 2 * s1 - distance1;
    set1.insert(f);
    dfs3(1, -1);
    dfs4(1, -1);
    s = min(s, s2);
    cout << s << "\n";
}
