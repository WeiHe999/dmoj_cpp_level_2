#include <bits/stdc++.h>
using namespace std;

long long find_root(long long node, vector <long long> &roots)
{
    if (node != roots[node]) roots[node] = find_root(roots[node], roots);
    return roots[node];
}

bool unify(long long node1, long long node2, vector <long long> &roots)
{
    long long root1 = find_root(node1, roots), root2 = find_root(node2, roots);
    if (root1 == root2) return false;
    roots[root1] = root2;
    return true;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    long long n, m, d, a, b, c;
    cin >> n >> m >> d;
    vector <vector <long long> > edges;
    unordered_map <long long, vector <pair <long long, long long> > > graph;
    vector <long long> roots(n + 1);
    for (long long x = 1; x <= n; x++) roots[x] = x;
    for (long long x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        if (x < n - 1) edges.push_back({c, 0, a, b});
        else edges.push_back({c, 1, a, b});
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    sort(edges.begin(), edges.end());
    bool flag = false;
    long long cnt = 0, ind = 1, heaviest = -1;
    for (auto cur_node : edges)
    {
        if (unify(cur_node[2], cur_node[3], roots))
        {
            if (cur_node[1]) cnt++;
            ind++;
        }
        if (ind == n)
        {
            if (cur_node[1] && cur_node[0] < d)
            {
                heaviest = cur_node[0];
                flag = true;
            }
            break;
        }
    }
    if (flag && d > 0)
    {
        for (int x = 1; x <= n; x++) roots[x] = x;
        for (auto cur_node : edges)
        {
            if (cur_node[0] < heaviest) unify(cur_node[2], cur_node[3], roots);
            else if (cur_node[0] == heaviest && !cur_node[1]) unify(cur_node[2], cur_node[3], roots);
            else if (cur_node[0] == heaviest) continue;
            else if (!cur_node[1])
            {
                if (unify(cur_node[2], cur_node[3], roots))
                {
                    if (cur_node[0] <= d) cnt--;
                    break;
                }
            }
        }
    }
    cout << cnt << "\n";
}
