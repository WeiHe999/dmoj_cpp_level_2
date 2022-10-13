#include <bits/stdc++.h>
using namespace std;
unordered_map <int, vector <int> > graph;

void dfs(unordered_set <int> &visited, unordered_map <int, int> &parents, int start_node, int end_node)
{
    visited.insert(start_node);
    for (auto x : graph[start_node])
    {
        if (!visited.count(x))
        {
            visited.insert(x);
            parents[x] = start_node;
            dfs(visited, parents, x, end_node);
        }
    }
}

int bfs(vector <int> vec1, unordered_set <int> rabbits, int n)
{
    queue <int> q1;
    vector <int> dist(n + 1, -1);
    for (auto a : vec1)
    {
        q1.push(a);
        dist[a] = 0;
        if (rabbits.count(a)) return 0;
    }
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto x : graph[cur_node])
        {
            if (dist[x] == -1)
            {
                dist[x] = dist[cur_node] + 1;
                if (rabbits.count(x)) return dist[x];
                q1.push(x);
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, r, a, b, c, x, y;
    cin >> n >> r;
    for (int x = 0; x < n - 1; x++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
    }
    unordered_set <int> rabbits;
    for (int x = 0; x < r; x++)
    {
        cin >> c;
        rabbits.insert(c);
    }
    cin >> x >> y;
    unordered_set <int> visited;
    unordered_map <int, int> parents;
    dfs(visited, parents, x, y);
    vector <int> vec1 = {x, y};
    int cur = parents[y];
    while (cur != x)
    {
        vec1.emplace_back(cur);
        cur = parents[cur];
    }
    cout << bfs(vec1, rabbits, n) << "\n";
}
