#include <bits/stdc++.h>
using namespace std;

int bfs(int a, int b)
{
    if(a==b) return 0;
    queue <int> q1;
    q1.push(a);
    unordered_map <int, int> dist;
    unordered_set <int> visited;
    visited.insert(a);
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        vector<int> children = {2 * cur_node, cur_node - 1, cur_node + 1};
        for (auto x: children)
        {
            if (!visited.count(x) && x>=0 && x<= 100000)
            {
                visited.insert(x);
                dist[x] = dist[cur_node] + 1;
                if (x == b)
                {
                    return dist[x];
                }
                q1.push(x);
            }
            
        }
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << "\n";
}
