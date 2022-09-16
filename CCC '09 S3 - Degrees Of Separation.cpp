#include <bits/stdc++.h>
using namespace std;

int bfs(unordered_map <int, unordered_set <int> > graph, int start_node, int end_node)
{
    if (start_node == end_node) return 0;
    unordered_set <int> visited;
    visited.insert(start_node);
    unordered_map <int, int> dist;;
    queue <int> q1;
    q1.push(start_node);
    while (!q1.empty())
    {
        int cur_node = q1.front();
        q1.pop();
        for (auto x : graph[cur_node])
        {
            if (!visited.count(x))
            {
                visited.insert(x);
                dist[x] = dist[cur_node] + 1;
                if (x == end_node)
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
    unordered_map <int, unordered_set <int> > graph = {{1, {6}}, {2, {6}}, {3, {4, 5, 6, 15}}, {4, {3, 5, 6}}, {5, {3, 4, 6}},
    {6, {1, 2, 3, 4, 5, 7}}, {7, {6, 8}}, {8, {7, 9}}, {9, {8, 10, 12}}, {10, {9, 11}}, {11, {10, 12}}, 
    {12, {9, 11, 13}}, {13, {12, 14, 15}}, {14, {13}}, {15, {3, 13}}, {16, {17, 18}}, {17, {16, 18}}, {18, {16, 17}}};
    char op;
    cin >> op;
    int x, y;
    while (op != 'q')
    {
        if (op == 'i')
        {
            cin >> x >> y;
            graph[x].insert(y);
            graph[y].insert(x);
        }
        else if (op == 'd')
        {
            cin >> x >> y;
            graph[x].erase(y);
            graph[y].erase(x);
        }
        else if (op == 'n')
        {
            cin >> x;
            
            cout << graph[x].size() << "\n";
        }
        else if (op == 'f')
        {
            cin >> x;
            unordered_set <int> s1, s2;
            s1.insert(x);
            for (auto a : graph[x]) s1.insert(a);
            for (auto a : graph[x])
            {
                for (auto b : graph[a])
                {
                    if (!s1.count(b)) s2.insert(b);
                }
            }
            cout << s2.size() << "\n";
        }
        else
        {
            cin >> x >> y;
            int r = bfs(graph, x, y);
            if (r==-1) cout << "Not connected\n";
            else cout << r << "\n";
        }
        cin >> op;
    }
}
