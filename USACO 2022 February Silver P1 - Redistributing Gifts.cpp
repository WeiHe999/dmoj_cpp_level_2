#include <bits/stdc++.h>
using namespace std;

void bfs(unordered_map <int, vector <int> > graph, int start_node, int n, vector <vector <bool> > &reachable)
{
    queue <int> q1;
    vector <bool> vis(n + 1);
    q1.push(start_node);
    vis[start_node] = true;
    reachable[start_node][start_node] = true;
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto a : graph[cur_node])
        {
            if (!vis[a])
            {
                vis[a] = true;
                reachable[start_node][a] = true;
                q1.push(a);
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n;
    cin >> n;
    vector <vector <int> > vec1(n, vector <int>(n));
    unordered_map <int, vector <int> > graph;
    bool flag;
    for (int x = 0; x < n; x++)
    {
        flag = true;
        for (int y = 0; y < n; y++)
        {
            cin >> vec1[x][y];
            if (flag) graph[x + 1].emplace_back(vec1[x][y]);
            if (vec1[x][y] == x + 1) flag = false;
        }
    }
    vector <vector <bool> > reachable(n + 1, vector <bool>(n + 1));
    for (int x = 1; x <= n; x++)
    {
        bfs(graph, x, n, reachable);
    }
    vector <bool> vis(n + 1);
    for (int cow = 1; cow <= n; cow++)
    {
        for (auto toy : graph[cow])
        {
            if (reachable[toy][cow])
            {
                //vis[toy] = true;
                cout << toy << "\n";
                break;
            }
        }
    }
}
