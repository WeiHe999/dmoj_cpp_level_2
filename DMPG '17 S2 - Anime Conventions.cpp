#include <bits/stdc++.h>
using namespace std;

int find_root(int node, vector <int> &roots)
{
    vector <int> vec1;
    int x = node;
    while (x != roots[x])
    {
        vec1.emplace_back(x);
        x = roots[x];
    }
    for (auto a : vec1) roots[a] = x;
    return x;
}

void unify(int node1, int node2, vector <int> &roots, vector <int> &comp_size)
{
    int root1 = find_root(node1, roots), root2 = find_root(node2, roots);
    if (comp_size[root1] > comp_size[root2])
    {
        roots[root2] = root1;
        comp_size[root1] += comp_size[root2];
        comp_size[root2] = 0;
    }
    else
    {
        roots[root1] = root2;
        comp_size[root2] += comp_size[root1];
        comp_size[root1] = 0;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, q, b, c;
    cin >> n >> q;
    char a;
    vector <int> roots(n + 1), comp_size(n + 1);
    for (int x = 1; x <= n; x++)
    {
        roots[x] = x;
        comp_size[x] = 1;
    }
    for (int x = 0; x < q; x++)
    {
        cin >> a >> b >> c;
        if (a == 'A') unify(b, c, roots, comp_size);
        else
        {
            if (find_root(b, roots) == find_root(c, roots)) cout << "Y\n";
            else cout << "N\n";
        }
    }
}
