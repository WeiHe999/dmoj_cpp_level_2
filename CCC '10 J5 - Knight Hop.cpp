#include <bits/stdc++.h>
using namespace std;

int bfs(pair <int, int> node, pair <int, int> end, map <pair <int, int>, int> &distance)
{
    if (node == end) return 0;
    set <pair <int, int> > vis;
    queue <pair <int, int> > q1;
    vis.insert(node);
    q1.push(node);
    while (!q1.empty())
    {
        pair <int, int> cur_node = q1.front();
        q1.pop();
        vector <pair <int, int> > vec1;
        int x = cur_node.first, y = cur_node.second;
        vec1 = {{x + 1, y + 2}, {x + 2, y + 1}, {x + 2, y - 1}, {x + 1, y - 2}, {x - 1, y - 2},
        {x - 2, y - 1}, {x - 2, y + 1}, {x - 1, y + 2}};
        for (auto a : vec1)
        {
            if (a.first > 0 && a.first < 9 && a.second > 0 && a.second < 9 && !vis.count(a))
            {
                vis.insert(a);
                q1.push(a);
                distance[a] = distance[cur_node] + 1;
                if (a.first == end.first && a.second == end.second) return distance[a];
            }
        }
    }
    return -1;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    map <pair <int, int>, int> distance;
    distance[{a, b}] = 0;
    cout << bfs({a, b}, {c, d}, distance) << "\n";
}
