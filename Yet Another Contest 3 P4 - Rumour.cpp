#include <bits/stdc++.h>
using namespace std;

unordered_map <int, vector <int> > graph;
int n, a, b, centroid = -1, start = 1;
vector <int> size1;
vector <bool> removed;

void dfs1(int cur, int prev)
{
    size1[cur] = 1;
    for (auto x : graph[cur])
    {
        if (x == prev || removed[x]) continue;
        dfs1(x, cur);
        size1[cur] += size1[x];
    }
}

void dfs2(int cur, int prev, int tot_size)
{
    bool flag = true;
    for (auto x : graph[cur])
    {
        if (x == prev || removed[x]) continue;
        if (size1[x] > tot_size / 2)
        {
            dfs2(x, cur, tot_size);
            flag = false;
        }
    }
    if (flag)
    {
        centroid = cur;
        removed[cur] = true;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n;
    size1.resize(n + 1);
    removed.resize(n + 1, false);
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    while (start != 0)
    {
        dfs1(start, -1);
        dfs2(start, -1, size1[start]);
        cout << centroid << "\n" << flush;
        cin >> start;
    }
    return 0;
}
