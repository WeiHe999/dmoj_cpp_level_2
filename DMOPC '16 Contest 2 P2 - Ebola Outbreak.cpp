#include <bits/stdc++.h>
using namespace std;

int find_root(int node, vector <int> &roots)
{
    if (node != roots[node]) roots[node] = find_root(roots[node], roots);
    return roots[node];
}

void unify(int node1, int node2, vector <int> &roots)
{
    int root1 = find_root(node1, roots), root2 = find_root(node2, roots);
    if (root1 == 1) roots[root2] = root1;
    else roots[root1] = root2;
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, k, a, prev;
    cin >> n >> m;
    vector <int> roots(n + 1);
    for (int x = 1; x <= n; x++) roots[x] = x;
    for (int x = 0; x < m; x++)
    {
        cin >> k;
        for (int y = 0; y < k; y++)
        {
            cin >> a;
            if (y == 0) prev = a;
            else
            {
                unify(a, prev, roots);
                prev = a;
            }
        }
    }
    set <int> s1;
    for (int x = 1; x <= n; x++) if (find_root(x, roots) == 1) s1.insert(x);
    cout << s1.size() << "\n";
    for (auto x : s1) cout << x << " ";
    cout << "\n";
}
