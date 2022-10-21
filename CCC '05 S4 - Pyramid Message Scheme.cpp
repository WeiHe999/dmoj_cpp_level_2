#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map <string, unordered_set <string> > graph, string start_node)
{
    queue <string> q1;
    unordered_map <string, int> dist;
    q1.push(start_node);
    dist[start_node] = 0;
    int max_depth = 0;
    while (!q1.empty())
    {
        string cur = q1.front();
        q1.pop();
        for (auto x : graph[cur])
        {
            if (!dist.count(x))
            {
                dist[x] = dist[cur] + 1;
                max_depth = max(dist[x], max_depth);
                q1.push(x);
            }
        }
    }
    return max_depth;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int t;
    cin >> t;
    for (int a = 0; a < t; a++)
    {
        int n;
        cin >> n;
        unordered_map <string, unordered_set <string> > graph;
        vector <string> vec1(n);
        for (int x = 0; x < n; x++) cin >> vec1[x];
        string start_node = vec1.back();
        for (int b = 0; b < n; b++)
        {
            if (b == 0)
            {
                graph[vec1[b]].insert(vec1.back());
                graph[vec1.back()].insert(vec1[b]);
            }
            else
            {
                graph[vec1[b]].insert(vec1[b - 1]);
                graph[vec1[b - 1]].insert(vec1[b]);
            }
        }
        cout << (n - bfs(graph, start_node) * 2) * 10 << "\n";
    }
}
