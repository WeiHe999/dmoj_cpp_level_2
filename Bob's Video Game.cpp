#include <bits/stdc++.h>
using namespace std;

int MM = 1e9;

void floyd_warshall(vector <vector <int> > &adj, int n)
{
    for (int mid = 1; mid <= n; mid++)
    {
        for (int beg = 1; beg <= n; beg++)
        {
            for (int end = 1; end <= n; end++)
            {
                adj[beg][end] = min(max(adj[beg][mid], adj[mid][end]), adj[beg][end]);
            }
        }
    }
}

int main()
{
    cin.tie(0); cout.tie(0); cin.sync_with_stdio(0);
    int n, m, t, a, b, c;
    cin >> n >> m >> t;
    vector <vector <int> > adj(n + 1, vector <int>(n + 1, MM));
    for (int x = 0; x < m; x++)
    {
        cin >> a >> b >> c;
        adj[a][b] = c;
    }
    floyd_warshall(adj, n);
    for (int x = 0; x < t; x++)
    {
        cin >> a >> b;
        if (adj[a][b] != MM) cout << adj[a][b] << "\n";
        else cout << "-1\n";
    }
}
