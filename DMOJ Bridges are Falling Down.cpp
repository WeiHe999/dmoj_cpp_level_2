#include <bits/stdc++.h>
using namespace std;
#define int long long

unordered_map <int, vector <int> > graph;
vector <int> roots, size1;
vector <pair <int, int> > vec1;
unordered_set <int> s1;
int n, m, a, b, s = 0;

int find_root(int node)
{
    if (node != roots[node]) roots[node] = find_root(roots[node]);
    return roots[node];
}

void unify(int node1, int node2)
{
    int root1 = find_root(node1), root2 = find_root(node2);
    if (root1 == root2) return;
    s -= (size1[root1] * (size1[root1] - 1)) / 2;
    s -= (size1[root2] * (size1[root2] - 1)) / 2;
    s += ((size1[root1] + size1[root2]) * (size1[root1] + size1[root2] - 1)) / 2;
    if (size1[root1] >= size1[root2])
    {
        roots[root2] = root1;
        size1[root1] += size1[root2];
        size1[root2] = 0;
        s1.insert(root1);
        s1.erase(root2);
    }
    else
    {
        roots[root1] = root2;
        size1[root2] += size1[root1];
        size1[root1] = 0;
        s1.insert(root2);
        s1.erase(root1);
    }
}

int32_t main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    cin >> n >> m;
    roots.resize(n + 1);
    for (int i = 1; i <= n; i++) roots[i] = i;
    size1.resize(n + 1, 1);
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        graph[a].emplace_back(b);
        graph[b].emplace_back(a);
        vec1.push_back({a, b});
    }
    reverse(vec1.begin(), vec1.end());
    vector <int> vec3;
    for (int i = 0; i < vec1.size(); i++)
    {
        vec3.emplace_back(((n * (n - 1)) / 2) - s);
        unify(vec1[i].first, vec1[i].second);
    }
    for (int i = vec3.size() - 1; i >= 0; i--) cout << vec3[i] << "\n";
}
